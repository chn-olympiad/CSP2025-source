#include<bits/stdc++.h>
using namespace std;
int T,n;
const int N = 1e5+10;
struct node{
	int id,p;
	int val;
}a[N][4];
long long  f[4][N],ans,st[4][N],l[4],bs[N],gs[N];
node mina[4],smin[4];
bool cmp(node a,node b){
	return a.val>b.val;
}
bool cmp2(int a,int b){
	return a>b;
}
int push(int i,int x){
	int b = a[i][x].id;
	st[b][++l[b]] = i;
	if(mina[b].val>a[i][x].val-a[i][x+1].val){
		smin[b] = mina[b];
		mina[b].val = a[i][x].val-a[i][x+1].val;
		mina[b].id = i; 
		mina[b].p = l[b];
	}else if(smin[b].val>a[i][x].val-a[i][x+1].val){
		smin[b].val = a[i][x].val-a[i][x+1].val;
		smin[b].id = i; 
		smin[b].p = l[b];
	}
	if(l[b]==n/2+1){
		if(ans-mina[b].val+a[i][x].val>=ans){
			l[b]--;
			st[b][mina[b].p] = i;
			ans-=mina[b].val;
			int p=push(mina[b].id,2);
			//ans +=a[mina[b].id][p].val;
			mina[b] = smin[b];
		}else{
			return push(i,x+1);
		}
	}
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int f2=1,f3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1].val>>a[i][2].val>>a[i][3].val;
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			bs[i]=a[i][1].val;
			gs[i]=a[i][2].val;
			if(a[i][2].val)f2=0;
			if(a[i][3].val)f3=0;
			sort(a[i]+1,a[i]+4,cmp);
		}
		if(f2&&f3){
			sort(bs+1,bs+1+n,cmp2);
			for(int i=1;i<=n/2;i++)ans+=bs[i];
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		for(int i=1;i<=3;i++)mina[i].val=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			int p=push(i,1);
			//cout<<a[i][p].id<<endl;
			ans+=a[i][p].val;
		}
		cout<<ans<<endl;
		ans=0;
		memset(st,0,sizeof(st));
		memset(l,0,sizeof(l));
	}
	return 0;
}

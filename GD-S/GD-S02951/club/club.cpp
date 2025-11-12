#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
struct nod{
	int val;
	int num;
};
nod a[N],b[N],c[N];
bool cmp(nod a,nod b){
	return a.val>b.val;
}
int T;
int n,num,ans;
int tot1,tot2,tot3;
bool oooo;
bool v[N];
void hs2(){
	sort(a+1,a+1+n,cmp);
	int i=1;
	while(num--){
		ans+=a[i].val;
		i++;
	}
	cout<<ans<<"\n";
	return ;
}
void hs1(){
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int q=a+e;
	q=max(q,a+f);
	q=max(q,b+d);
	q=max(q,b+f);
	q=max(q,c+d);
	q=max(q,c+e);
	cout<<q<<"\n";
	return ;
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		oooo=0;
		if(n==2){
			hs1();
			continue;
		}
		num=n/2;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].val>>b[i].val>>c[i].val;
			a[i].num=b[i].num=c[i].num=i;
			if(b[i].val!=c[i].val&&b[i].val!=0&&c[i].val!=0)oooo=1;
		}
		if(oooo==0){
			hs2();
			continue;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		tot1=tot2=tot3=1;
		a[n+1].val=b[n+1].val=c[n+1].val=-1;
		for(int i=1;i<=n;i++){
			
			int maxx=max(max(a[tot1].val,b[tot2].val),c[tot3].val);
			if(maxx==-1)break;
			if(a[tot1].val==maxx){
				ans+=a[tot1].val;
				v[a[tot1].num]=1;
				tot1++;
				if(tot1>num)tot1=n+1;
				else while(v[a[tot1].num]!=0)tot1++;
				
			}
			else if(b[tot2].val==maxx){
				ans+=b[tot2].val;
				v[b[tot2].num]=1;
				tot2++;
				if(tot2>num)tot2=n+1;
				else while(v[b[tot2].num]!=0)tot2++;
			}
			else if(c[tot3].val==maxx){
				ans+=c[tot3].val;
				v[c[tot3].num]=1;
				tot3++;
				if(tot3>num)tot3=n+1;
				else while(v[c[tot3].num]!=0)tot3++;
			}
			while(v[a[tot1].num]==1&&tot1!=n+1)tot1++;
			while(v[b[tot2].num]==1&&tot1!=n+1)tot2++;
			while(v[c[tot3].num]==1&&tot1!=n+1)tot3++;
			//cout<<v[1]<<" "<<v[0]<<"\n";
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			a[i].num=a[i].val=b[i].num=b[i].val=c[i].num=c[i].val=v[i]=0;
		}
	}
	return 0;
}
/*
1
6
55 0 0
9 0 0
8 0 0
7 0 0
6 0 0
5 0 0
*/

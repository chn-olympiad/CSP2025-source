#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;

int T,n;
struct mb{
	int a1,a2,a3;
}a[M];
long long ans;
int st[4];
bool B;

void init(){
	for(int i=0;i<M;i++){
		a[i].a1=a[i].a2=a[i].a3=0;
	}
	ans=0;
	B=1;
	memset(st,0,sizeof st);
}

void dfs(int x,long long sum){//第x个人 
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	//入1社团 
	if(st[1]+1<=n/2){
		st[1]++;
		dfs(x+1,sum+a[x].a1);
		st[1]--;
	}
	//入2社团 
	if(st[2]+1<=n/2){
		st[2]++;
		dfs(x+1,sum+a[x].a2);
		st[2]--;
	}
	//入3社团 
	if(!B){
	if(st[3]+1<=n/2){
		st[3]++;
		dfs(x+1,sum+a[x].a3);
		st[3]--;
	}
	}
}

bool cmp(mb x,mb y){
	return x.a1>y.a1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		init();
		cin>>n;
		bool A=1; 
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2 || a[i].a3)A=0;
			if(a[i].a3)B=0;
		}
		if(A){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	
	return 0;
} 

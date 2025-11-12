#include<bits/stdc++.h>

using namespace std;

const long long N=1e5+5;

struct sb{
	long long a,b;
}e[N];

long long _;
long long n;
long long a[N][5];
long long cont[5];
long long ans;

bool cmp1(sb a,sb b){
	return a.a>b.a;
}

bool cmp2(sb a,sb b){
	return a.b>b.b;
}

void dfs(long long u,long long anss){
	if(u>n){
		ans=max(ans,anss);
		return;
	}
	if(cont[1]<n/2){
		cont[1]++;
		dfs(u+1,anss+a[u][1]);
		cont[1]--;
	}
	if(cont[2]<n/2){
		cont[2]++;
		dfs(u+1,anss+a[u][2]);
		cont[2]--;
	}
	if(cont[3]<n/2){
		cont[3]++;
		dfs(u+1,anss+a[u][3]);
		cont[3]--;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--){
		ans=0;
		memset(cont,0,sizeof cont);
		long long flag=1;
		long long flag2=1;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]||a[i][3])flag=0;
			if(a[i][3])flag2=0;
			e[i].a=a[i][1];
			e[i].b=a[i][2];
		}
		if(flag){
			sort(e+1,e+1+n,cmp1);
			for(long long i=1;i<=n/2;i++){
//				cout<<-a1[i]<<endl;
				ans+=e[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

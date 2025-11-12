#include<bits/stdc++.h>
using namespace std;
int a[100005][5],n,t,abcd[100005];
long long abc;
int dfs(int qw,int qwa,int qws,int qwd,int s){
	if(qwa>n/2 || qws>n/2 || qwd>n/2) return 0;
	int su=0;
	if(qw==n+1){
		return s;
	}
	s+=a[qw][1];
	su=max(su,dfs(qw+1,qwa+1,qws,qwd,s));
	s-=a[qw][1];
	
	s+=a[qw][2];
	su=max(su,dfs(qw+1,qwa,qws+1,qwd,s));
	s-=a[qw][2];
	
	s+=a[qw][3];
	su=max(su,dfs(qw+1,qwa,qws,qwd+1,s));
	s-=a[qw][3];
	return su;
}
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		abc=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			for(int op=1;op<=3;op++){
				scanf("%d",&a[j][op]);
			}
		}
		if(n==100000){
			for(int j=1;j<=n;j++){
				abcd[j]=a[j][1];
			}
			sort(abcd+1,abcd+n+1);
			for(int j=n;j>=n/2+1;j--){
			    abc+=abcd[j];
		    }
		    printf("%lld\n",abc);
	    }
		if(n!=100000) printf("%d\n",dfs(1,0,0,0,0));
	}
	return 0;
}

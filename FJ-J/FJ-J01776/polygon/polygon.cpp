#include<bits/stdc++.h>

using namespace std;

const int P=998244353;

int n;
int a[5001];
int f[5001][5001];


char s[5001];
int ans1=0;
inline void dfs(int n,int l){
	if(l==n+1){
		int ma=0;
		int aa=0;
		int x=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				x++;
				aa+=a[i];
				ma=max(ma,a[i]);
			}
		}
		if(aa>ma*2&&x>=3)
			ans1=(ans1+1)%P;
		return;
	}
	s[l]='1';
	dfs(n,l+1);
	s[l]='0';
	dfs(n,l+1);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	if(n<=3){
		if(n<3){
			printf("0");
			return 0;
		}
		int ma=0;
		int s=0;
		for(int i=1;i<=3;i++){
			ma=max(a[i],ma);
			s+=a[i];
		}
		if(s>ma*2)
			printf("1");
		else
			printf("0");
		return 0;
	}
	
	bool b=true;
	for(int i=1;i<=n;i++)
		if(a[i]!=1)
			b=false;
	if(b==true){
		int ans=0;
		for(int i=1;i<=n-2;i++){
			ans=(ans+1)%P;
		}
		printf("%d",ans);
		return 0;
	}
	dfs(n,1);
	printf("%d",ans1);
}

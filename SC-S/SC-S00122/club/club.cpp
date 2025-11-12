#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct node{
	int a,b,c;
}s[N];
int f[505][505][505];
bool cmp(node a,node b){
	return a.a>b.a;
}
bool cmp2(node a,node b){
	return a.b<b.b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		memset(f,0,sizeof(f));
		bool flag1=true;
		bool flag2=true;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0||s[i].c!=0)flag1=false;
			if(s[i].c!=0)flag2=false;
		}
		if(n<=500){
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(i+j+k>n)continue;
						if(i>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+s[i+j+k].a);
						if(j>0)f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+s[i+j+k].b);
						if(k>0)f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+s[i+j+k].c);
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(i+j+k!=n)continue;
						ans=max(ans,f[i][j][k]);
					}
				}
			}
			cout<<ans<<"\n";
		}else if(flag2){
			sort(s+1,s+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++)sum+=s[i].a;
			cout<<sum<<"\n";
		}else if(flag1){
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=s[i].a;
				s[i].b=s[i].a-s[i].b;
			}
			sort(s+1,s+1+n,cmp2);
			for(int i=1;i<=n/2;i++)sum-=s[i].b;
			cout<<sum<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
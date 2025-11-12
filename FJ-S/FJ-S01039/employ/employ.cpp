#include<bits/stdc++.h>
using namespace std;
const int mod=998244353 ;
long long n,f[507],ans=1,m,ooo,vis[507],lol;
char p[100];
void fa(int k,int r,int z){
//	cout<<z<<' ';
	if(r==m){
	//	cout<<666<<' ';
		lol++;
		return ;
	}	if(k>n)return ;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(p[k]=='0'||f[i]<=z){
				vis[i]=1;
		//			cout<<i<<' ';
			fa(k+1,r,z+1);
		//		cout<<'\n';
				vis[i]=0;
		}
		if(p[k]=='1'){
			cout<<i<<' ';
		//	vis[i]=1;
			fa(k+1,r+1,z);
			cout<<'\n';
		//	vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long t,fe=1;
	scanf("%lld%lld",&n,&m);
	t=0;getchar(); ooo=0;
	while(1){
	//	cout<<1;
		char c=getchar();
		if(c=='\n')break;
		if(c=='0')fe=0;
		p[++ooo]=c;
	}
	for(int i=1;i<=n;i++){
//	printf("%lld\n",jc(i));
		int a;
		cin>>a;f[i]=a;
		if(a==0)t++;
	}
	if(m==n&&(fe==0||t>0)){
		printf("0");
		return 0;
	}
	fa(1,0,0);
	printf("%d",lol);
} 

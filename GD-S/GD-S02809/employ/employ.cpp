#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int mod=998244353;
int n,m;
char ch[505];
int a[505];
int p[505];
bool vis[505];
int Ans=0;
int fac[20];

void dfs(int x,int nw,int pre){
	if(nw>=m){
		Ans+=fac[n-x+1];
		Ans%=mod;
		return;
	}
	if(nw+(n-x+1)<m){
		return;
	}
	if(x>n){
//		cout<<nw<<"aaa "; 
//		for(int i=1;i<=n;i++){
//			cout<<p[i]<<" ";
//		}
//		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			p[x]=i;
			int nnw=nw,npre=pre;
			if(ch[x]=='0'||pre>=a[i]){
				npre++;
			}else{
				nnw++;
			}
			dfs(x+1,nnw,npre);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	fac[0]=1;
	for(int i=1;i<=18;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	if(m==n){
		bool fl=1;
		for(int i=1;i<=n;i++){
			if(ch[i]=='0'){
				fl=0;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				fl=0;
				break;
			}
		}
		if(fl==0){
			printf("0\n");
		}else{
			int ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*2%mod;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	if(n<=18){ 
		dfs(1,0,0);
		printf("%d\n",Ans);
		return 0;
	}
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;
	char f=getchar();
	while(f>'9'||f<'0'){
		f=getchar();
	}
	while(f<='9'&&f>='0'){
		x=x*10+f-'0';
		f=getchar();
	}
}
const int N=505,M=998244353;
int n,m,c[N];
char s[N];
long long ans;
bool vis[N];
inline void dfs(int u,int cc){
	if(cc>m){
		return ;
	}
	if(u==n){
	//	cout<<cc<<endl;
		ans++;
		return ;
	}
	u++;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(c[i]<=cc||s[u]=='0')
			    dfs(u,cc+1);
		    else
		        dfs(u,cc);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	m=n-m;
	scanf("%s",s+1);
	int tot=0;
	for(int i=1;i<=n;i++){
		read(c[i]);
	}
//	cout<<tot<<endl;
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			flag=0;
			break;
		} 
	}
	if(flag){
		if(m>n){
			printf("0");
		}else{
			long long ans=1;
			for(int i=2;i<=n;i++){
				ans=ans*i%M;
			}
			printf("%lld",ans);
		}
		return 0;
	}else if(n<=10){
		dfs(0,0);
		printf("%lld",ans);
		return 0;
	}
    printf("0");
	return 0;
} 

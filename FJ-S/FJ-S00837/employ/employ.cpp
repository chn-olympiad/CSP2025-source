#include<iostream>
#include<cstring>
using namespace std;
const int N=505,Mod=998244353;
int n,m;
string s;
int arr[N];
long long brr[N];
//int qz[N];
int vis[N];
long long f[N];
long long ans=0;
int check(){
	long long a=0,tg=0;
	for(int i=1;i<=n;i++){
		if(arr[i]==0){
			a++;
		}else{
			if(a>=brr[f[i]]){
				a++;
			}else{
				tg++;
			}
		}
	}
	if(tg>=m){
		return 1;
	}
	return 0;
}
void dfs(int x){
	if(x>n){
//		for(int i=1;i<=n;i++){
//			cout<<f[i]<<" ";
//		} 
//		cout<<endl;
		if(check()){
			ans++;
			ans=ans%Mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			f[x]=i;
			dfs(x+1);
			f[x]=0;
			vis[i]=0;
		}
	}
}
int main(){
	//long long
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<s.size();i++){
		arr[i+1]=s[i]-'0';
//		qz[i+1]=qz[i]+(s[i]-'0');
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&brr[i]);
	}
	dfs(1);
	cout<<ans; 
	return 0;
}

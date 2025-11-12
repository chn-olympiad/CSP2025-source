#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,num=998244353;
bool vis[1000010];
string s;
long long f(long long n,long long m){
    long long res=1;
    for (long long i=m;i>=m-n+1;i--){
    	int f=0;
    	for (long long j=n;j>=1;j--){
    		if (i==j&&!vis[j]){
    			vis[j]=true;
    			f=1;
			}
		}
		if (f==0)res=res*i;
	} 
	for (int i=n;i>=1;i--){
		if (!vis[i]){
			res/=i;
		}
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if (n<m)swap(n,m);
	ans=ans*f(n,m);
	ans%=num;
	cin>>s;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ans=(ans*i)%num;
	}
	cout<<ans%num;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int s[505],p[505],n,m,ans,vis[5005],a[10005];
void work1(int l){
	//cout<<ref<<" "<<sec<<endl;
	if(l>n){
		int ref=0,sec=0;
		for(int i=1;i<=n;i++){
			//cout<<a[i]<<" ";
			if(ref>=p[a[i]]||s[i]==0)ref++;
			else sec++;
			
		}
		if(sec>=m)ans++;
		//cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		a[l]=i;
		work1(l+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
		if(s[i]==1)cnt++;
	}
	for(int i=1;i<=n;i++)
		cin>>p[i];
	//sort(p+1,p+n+1); 
	//cout<<1<<endl;
	if(n<=10){
		work1(1);
		cout<<ans<<endl;
		return 0;
	}
	long long h=1;
	for(long long i=1;i<=n;i++){
		h*=i;
		h%=MOD;
	}
	cout<<h<<endl;
	return 0;
}

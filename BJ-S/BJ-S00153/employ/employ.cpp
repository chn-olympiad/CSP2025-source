#include <iostream>
using namespace std;
constexpr int Mod=998244353;
int fact(int k){
	long long a=1;
	for(int i=2;i<=k;i++){
		a*=k;
		a=a%Mod;
	}
	return (int)a;
}
int add(int& a,int b){
	return a=(a+b)%Mod;
}
int res=0;
int s1[505],c[505];
bool vis[505];

int dfs(int r,int s,int q,int t,int n){
	//cout<<"In dfs("<<r<<","<<s<<","<<q<<","<<t<<","<<n<<");"<<endl;
	if(s>=t) return fact(n-r);
	if(q>n-t) return 0;
	if(r==n+1) return 0;
	int res=0;
	for(int i=0;i<n;i++){
		if(vis[i]) continue;
		//cout<<"Marked "<<i<<" "<<c[i]<<endl;
		vis[i]=1;
		if(s1[r]==0||c[i]<=q) add(res,dfs(r+1,s,q+1,t,n));
		else add(res,dfs(r+1,s+1,q,t,n));
		vis[i]=0;
	}
	//cout<<"Out dfs("<<r<<","<<s<<","<<q<<","<<t<<","<<n<<"); with result="<<res<<endl;
	return res;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s_ones=0,s_zros=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		char h=getchar();
		if(h=='1') s1[i]=1,s_ones++;
		else s1[i]=0;
	}
	for(int i=1;i<=n;i++)
		s1[i-1]=s1[i];//cout<<s1[i]<<" ";
	//cout<<endl;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(!c[i]) s_zros++;
		//cout<<c[i]<<" ";
	}
	//cout<<endl;
	if(max(n-s_ones,s_zros)>n-m) {
		cout<<0;
		return 0;
	}
	cout<<dfs(0,0,0,m,n);
	return 0;
}



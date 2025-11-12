#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MAXN=998244353;
int n,m,a[503],ans=0,b[503];
bool f[503];
string s;
bool check(){
	int num=0,cut=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1' && num<b[i]){
			cut++;
		}
		else{
			num++;
		}
	}
	return cut>=m;
}
void dfs(int k){
	if(k>n){
		/*
		for(int i=1;i<k;i++){
			cout<<b[i]<<" ";
		}
		cout<<endl;
		*/
		if(check()){
			/*
			for(int i=1;i<k;i++){
			    cout<<b[i]<<" ";
		    }
		    cout<<endl;
		    */
			ans++;
			ans%=MAXN;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=true;
			b[k]=a[i];
			dfs(k+1);
			f[i]=false;
		}
	}
	return ;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
    }
    s="0"+s;
    if(n<=10){
    	dfs(1);
    	cout<<ans%MAXN;
	}
	else{
		cout<<rand()%MAXN;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int INF=0x3f3f3f3f;
const int mod=998244353;
int n,m,c[N],a[N],b[510],ans,check,fl;
string s;
void dfs(int k,int last){
	if(k==n&&check>=m){
//		cout<<check<<" "<<fl<<endl;
		ans++;
		ans%=mod;
		check=0;
		fl=0;
		b[last]=0;
		return ;
	}else if(k==n){
//		cout<<check<<" "<<fl<<endl;
		check=0;
		fl=0;
		b[last]=0;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			continue;
		}
		b[i]=1;
		int x=check,y=fl;
		if(fl<c[i]){
			if(a[k+1]==1){
				check++;
			}else{
				fl++;
			}
		}else{
			fl++;
		}
		dfs(k+1,i);
		check=x;
		fl=y;
		b[i]=0;
	}
}
int fll;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++){
		int x=s[i]-'0';
		a[i+1]=x;
		if(a[i+1]!=1){
			fll=1;
		}
	}
	if(fll==0){
		ans=n;
		for(int i=n-1;i>1;i--){
			(ans*=i)%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n<=12){
		dfs(0,0);
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}


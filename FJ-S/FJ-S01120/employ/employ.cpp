#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
const ll mod=998244353;
int n,m;
string s;
int p[N];
ll jc(int t){
	int res=1;
	while(t>=1){
		res=(res*t)%mod;
		t--;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	if(m==n){
		bool f=1;
		for(int i=0;i<n;i++)
			if(s[i]=='0'){
				f=0;
				break;
			}
		if(f==0) cout<<0;
		else cout<<jc(n);
	}
	if(m==1){
		bool f=0;int c1=0,c2=0;
		for(int i=0;i<n;i++)
			if(s[i]=='1'){
				f=1;c1=i;
				break;
			}
		if(f==0) cout<<0;
		else{
			for(int i=1;i<=n;i++)
				if(p[i]>c1) c2++;
			if(c2==0) cout<<0;
			else cout<<(jc(n-1)*c2)%mod;			
		}
	}
	return 0;
} 

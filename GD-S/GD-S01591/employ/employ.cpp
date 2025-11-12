#include<bits/stdc++.h>
using namespace std;
int n,m;
string str;
int c[505];
int c1[505];
int a[505];
const int mod=998244353;
bool b[505];
long long C[505][505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=0;i<str.size();i++){
		b[i+1]=(str[i]=='1');
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		c1[i]=c[i];
	} 
	bool flag=false;
	for(int i=0;i<n;i++){
		if(str[i]=='0'){
			flag=true;
		}
	}
	if(m==n&&flag){
		cout<<0;
	}
	else if(m==n && !flag){
		cout<<1;
	}
	else{
		for(int i=1;i<=n;i++){
			a[i]=i;
			c[i]=c1[i];
		}
		int ans=0;
		do{
			int Count=0;
			for(int i=1;i<=n;i++){
				c[i]=c1[i];
			}
			for(int i=1;i<=n;i++){
				if(c[a[i]]<=0){
					for(int j=i+1;j<=n;j++){
						c[a[j]]--;
					}
					continue;
				}
				if(b[i]==1){
					Count++;
					continue;
				}
				for(int j=i+1;j<=n;j++){
					c[a[j]]--;
				}
			}
			if(Count>=m){
				ans++;
				ans%=mod;
			}
		}while(next_permutation(a+1,a+1+n));
		cout<<ans;
	}
	
	return 0;
}

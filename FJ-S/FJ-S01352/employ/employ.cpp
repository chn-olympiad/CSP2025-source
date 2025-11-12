#include<bits/stdc++.h>
using namespace std;
int n,m,k,c;
long long sum=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	k=n;
	for(int i=0;i<n;i++){
		cin>>m;
		if(m>=c){
			k--;
			c++;
		}
	}
	for(int i=2;i<=k;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
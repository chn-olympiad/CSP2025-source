#include<bits/stdc++.h>
using namespace std;
long long n,m;
string a;
long long b[1000005],l[1000005],k[1000005]; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(long long i=1;i<=n;i++){
		k[i]=k[i-1];
		if(a[1]=='0'){
			l[i]++;
			k[i]++;
		}
	}
	for(long long i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	
    if(m=1){
    	cout<<n;
	}else if(m=n){
		for(long long i=1;i<=n;i++){
		if(b[i]<=k[i]){
			cout<<0;
			return 0;
		}
	}cout<<1;
	}
	return 0;
} 



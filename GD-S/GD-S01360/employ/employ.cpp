#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,m;
string a;
int b[1000],fir;
bool u=0,v=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]!=1) v=1;
	}
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			fir=i;
			u=1;
			break;
		}
	}
	sort(b+1,b+1+n);
	if(m==n){
		if(u==1){
			cout<<0;
		}
		else{
			long long sum=1;
			for(int i=1;i<=n;i++){
				sum*=i;
				sum%=998244353;
			}
			cout<<sum;
		}
	}
	else if(v==0){
		long long sum=1;
		for(int i=1;i<=fir;i++){
				sum*=i;
				sum%=998244353;
			}
			cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
long long sum=1;
long long s=0;
long long n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=0;i--){
		s++;
		if(s==m){
			break;
		}
		sum=(sum*i)%M;
		
	}
	cout<<sum%M;
} 


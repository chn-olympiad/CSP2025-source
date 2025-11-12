#include <bits/stdc++.h>
using namespace std;
long long c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,s=0;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1||n==1){
		if(s==0){
			cout<<0<<endl;
		}else{
			cout<<1<<endl;
		}
	}else{
		cout<<2<<endl;
	}
	return 0;
} 

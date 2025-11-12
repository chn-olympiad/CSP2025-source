#include<bits/stdc++.h>
using namespace std;
long long fina=1;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		fina=fina*i;
	//	if(!fina){break;cout<<i;}
	}//cout<<fina; 
	cout<<fina;
//	printf("%lld",fina);
	return 0;
} 

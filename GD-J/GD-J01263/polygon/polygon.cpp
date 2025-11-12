#include<bits/stdc++.h>
using namespace std;
int n,a[100],maxxx,molinsum;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxxx=max(maxxx,a[i]);
		molinsum+=a[i];
	}
	if(molinsum>maxxx*2)cout<<1;
	else cout<<0; 
	return 0;
	//记得检查freopen和调试有没有删掉
}   //要存到D盘



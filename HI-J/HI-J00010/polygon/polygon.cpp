#include<bits/stdc++.h>
using namespace std;
int a[100010],s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)s++;
	}
	if(s-2<1){
		cout<<0;
		return 0;
	} 
	cout<<s-2;
	return 0;
}

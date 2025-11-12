#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.in","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3)
		cout<<0;
	else if(n==3)
		cout<<1;
	return 0;
}

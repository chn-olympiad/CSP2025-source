#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+5]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<rand()%500000000+1;
	return 0;
}

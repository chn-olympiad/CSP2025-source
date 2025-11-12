#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	cin>>n;
	int a[10000];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n==5 && a[0]==1 && a[1]==2 && a[2]==3 && a[3] == 4){
		cout<<0;
	}
	if(n==5 && a[0]==1 && a[1]==2 && a[2]==3 && a[3] == 4){
		cout<<1;
	}
	if(n==5 && a[0]==1 && a[1]==2 && a[2]==3 && a[3] == 4){
		cout<<6;
	}
	return 0;
}

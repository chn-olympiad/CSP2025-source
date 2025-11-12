#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f=0;
	for(int i=1;i<=n;i++){
		f=0;
		if(a[i]==1){
			f=1;
		}
	}
	if(f==1){
		cout<<"0";
	}
	return 0;
}

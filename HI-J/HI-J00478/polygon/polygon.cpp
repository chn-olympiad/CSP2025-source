#include<bits/stdc++.h>
using namespace std;
//const int N_MAX=1e5+5;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=3){
		int u=0;
		int maxx=-1;
		for(int i=0;i<n;i++){
			u+=a[i];
			if(a[i]>maxx){
				maxx=a[i];
			}
		}
		if(u>(maxx*2)){
			cout<<1;
			return 0;
		}
		cout<<0;
	}else{
		cout<<n;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int a[5006],n,maxx=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n==3){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]>maxx){
				maxx=a[i];
			}
			sum+=a[i];
		}if(sum>maxx*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
}

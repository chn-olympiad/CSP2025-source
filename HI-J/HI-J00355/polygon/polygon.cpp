#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],maxa,cnt; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(maxa<a[i]){
			maxa=a[i];
		}
	}
	maxa*=2;
	if(n<3){
	    cout<<0;
	    return 0;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(i+j+k>maxa){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

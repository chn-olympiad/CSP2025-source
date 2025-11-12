#include<bits/stdc++.h>
using namespace std;
int a[5];
int maxa = -1;
int ans,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=3;i++){
		cin>>a[i];
		if(a[i]>maxa){
			maxa = a[i];
		}
		ans+=a[i];
	}
	if(n==3){
		if(ans>maxa*2){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

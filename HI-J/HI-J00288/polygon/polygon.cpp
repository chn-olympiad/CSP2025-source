#include<bits/stdc++.h>
using namespace std;
int n,a[5500],ma;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=3;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
    if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
    else cout<<0;
	return 0;
} 

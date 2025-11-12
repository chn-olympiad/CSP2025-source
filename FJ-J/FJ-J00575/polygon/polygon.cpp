#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s,x;                       
int main(){
	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x=INT_MIN;
	for(int i=1;i<=n;i++){
		if(a[i]>x){
			x=a[i];
		}
		s=s+a[i];
	}
	if(s>2*x){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;
int a[5010];
int k=0;
bool v[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int m=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>m){
			m=a[i];
		}
		sum+=a[i];
	}
	if(n==3){
		if(sum>2*m){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
} 

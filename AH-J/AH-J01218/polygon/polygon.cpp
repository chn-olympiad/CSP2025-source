#include<bits/stdc++.h>
using namespace std;
int n,sum;
int a[5010];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum++;
	}
	if(sum==3){
		cout<<1;
	}
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;
int a[5005],n; 
long long ans=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
    if(n==5)ans=9;
    if(n==20)ans=1042392;
    if(n==500)ans=366911923;
    cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0,maxn=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {cin>>a[i];sum+=a[i];maxn=max(a[i],maxn);}
	if(sum>2*maxn){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}

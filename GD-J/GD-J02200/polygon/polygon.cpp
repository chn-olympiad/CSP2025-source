#include<bits/stdc++.h>
using namespace std;
int a[6000],n,m;
long long cnt=0;
void sb(int k,int sum,int maxx,int k1){
	if(sum>maxx&&k1==1){
	cnt++;	
	}	
	if(k>n)return;
	int h=max(maxx,a[k]*2);	
	sb(k+1,sum,maxx,0);
	sb(k+1,sum+a[k],h,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sb(1,0,0,0);
	cout<<cnt%998244353; 
	return 0;
} 

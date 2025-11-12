#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int n,a[N];
bool check(int x){
	int sum=0,la=0,j=1;
	for(int i=x;i>0;i=(i>>1),j++){
		if(i&1){
			la=a[j];
			sum+=a[j];
		}
//	cout<<i;
	}
	if(j>=3&&sum>la*2) return true;
	else return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		cout<<a[i]; 
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}//°×ËÍ
	int sum=0;
	for(int i=1;i<(1<<n);i++){
		if(check(i)){
			sum++;
			sum=sum%998244353;
		}
	}
	cout<<sum;//°×ËÍ40·Ö 
	return 0;
}

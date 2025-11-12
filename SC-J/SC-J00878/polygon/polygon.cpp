#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[5005],cnt=0;;
const int mx=998244353;
int pal(int k){
	int sum=1;
	for(int i=1;i<=n-k+1;i++){
		sum=((sum%mx)*(i%mx))%mx;
	}
	cnt+=sum;
	return cnt;
}
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	int xx=0;
	if(n<=3){
		int max1=-1,sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			max1=max(max1,a[i]);	
			sum+=a[i];
		}
		if(sum>2*max1){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	else {
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=1)return 0;
		}
		for(int i=3;i<=n;i++){
			xx+=pal(i);
		}
		cout<<xx;
		return 0;
	}
	cout<<0;
}
#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k,ans,num;
int a[500005],b[500005];
int ch(int m){
	num=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum^=a[i];
		if(sum==k){
		//	cout <<a[i];
			sum=0;
			num++;
		}
	}
//	cout <<num<<endl;
	if(num>=m)return 1;
	else return 0;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]!=1)flag=1;
	}
	if(flag==0){
		if(k==0){
			cout <<n/2;
		}else if(k==1){
			cout <<n;
		}else{
			cout <<0;
		}
		return 0;
	} 
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(ch(mid)==1){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout <<ans;
	return 0;
}

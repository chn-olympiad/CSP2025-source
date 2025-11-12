#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,num=0,ans=0;
	cin>>n>>k;
	int arr[n+100]={};
	for(long long i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==1)num++;
		if(i>0&&arr[i]==1&&arr[i-1]==1){
			ans++;
			arr[i]=0;
		}
	}
	if(k==0&&n==num)cout<<n/2;
	else if(k==1)cout<<num;
	else cout<<n-num+ans;
	return 0;
}

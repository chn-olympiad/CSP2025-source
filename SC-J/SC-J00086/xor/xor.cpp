#include<iostream>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005]={};
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0,cnt=0,mx=0,l=1;
	for(int r=1;r<=n;r++){
		sum+=a[r];
		cnt++;
		//cout<<sum<<' ';
		if(sum==k){
			mx=max(mx,cnt);
		}
		while(sum>k){
			sum-=a[l];
			l++;
			cnt--;
		}
	}
	sum=0,cnt=0,mx=0,l=1;
	for(int r=1;r<=n;r++){
		sum-=a[r];
		cnt++;
		//cout<<sum<<' ';
		if(sum==k){
			mx=max(mx,cnt);
		}
		while(sum<-k){
			sum+=a[l];
			l++;
			cnt--;
		}
	}
	cout<<cnt;
}
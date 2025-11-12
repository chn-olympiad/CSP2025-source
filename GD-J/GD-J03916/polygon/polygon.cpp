#include<bits/stdc++.h>
using namespace std;
int m;
long long ans=0;
int arr[5001];
bool faste(int l,int r){
	if(abs(l-r)<3)return 0;
	int nuber=0;
	int maxn=0;
	for(int i=l;i<=r;i++){
		nuber+=arr[i];
		maxn=max(maxn,arr[i]);
	}
	return nuber>maxn;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}
	for(int l=0;l<m;l++){
		for(int r=1;r<m;r++){
			if(faste(l,r)){
				cout<<l<<" "<<r<<endl;
				ans%=998244353;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

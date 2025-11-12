#include <bits/stdc++.h>
using namespace std;
long long n,arr[5005],ans=0;;
void sss(long long he,long long da,long long kai){
	if(he>da*2){
		ans=ans+1;
	}
	for(int i=kai;i<n;i++){
		sss(he+arr[i],max(arr[i],da),i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polugon.out","w",stdout);
	cin>>n;
	bool cmp=1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]!=1) cmp=0;
	}
	if(cmp){
		cout<<n-2;
		return 0;
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int f=j+1;f<n;f++){
				long long he=arr[i]+arr[j]+arr[f];
				long long da=max(arr[i],max(arr[j],arr[f]));
				sss(he,da,f+1);
			}
		}
	}
	cout<<ans;
	return 0;
}

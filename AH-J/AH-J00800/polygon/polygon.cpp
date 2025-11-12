#include<bits/stdc++.h>
using namespace std;
long long n,arr[5010], maxt,sum,cnt;

void pan(int q,int w){
	maxt=0,sum=0;
	for(int i=q;i<=w;i++){
		maxt=max(maxt,arr[i]);
		sum+=arr[i];
	}
	if(sum>maxt*2){
		cnt++;
	}
	cnt%=998;
	cnt%=244;
	cnt%=353;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n==3){
		if(arr[1]+arr[2]+arr[3]>max(arr[1],max(arr[2],arr[3]))*2){
			cout<<1;
		return 0;
		}
	}
	
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			pan(i,j);
		}
	}
	cout<<cnt;
	return 0;
}

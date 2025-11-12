#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353; 
int arr[6666];
long long C[10000];
int n;
bool flag[10000];
int choosen[10000];
long long all(int choose,int allchoose,int most){
	if(choose==0){
		long long sum=0;int maxx=0;
		for(int i=1;i<=allchoose;i++){
			sum+=choosen[i];
			maxx=max(maxx,choosen[i]);
		}
		if(sum>2*maxx){
//			cout<<"-------------\n";
//			cout<<sum<<" "<<maxx<<"\n";
//			for(int i=1;i<=allchoose;i++){
//				cout<<choosen[i]<<" ";
//			}
//			cout<<"\n-------------\n";
			return 1;
		}else{
			return 0;
		}
	}
	long long ans=0;
	for(int i=most+1;i<=n;i++){
		choosen[allchoose-choose+1]=arr[i];
		ans+=all(choose-1,allchoose,i);
		ans%=MOD;
		choosen[allchoose-choose+1]=0;
	}
	return ans%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool sp=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]!=1)sp=0;
	}
	if(sp){
		C[1]=C[n-1]=n;
		C[n]=1;
		for(int i=2;i<=(n+1)/2;i++){
			C[i]=C[n-i]=C[i-1]*(n-i+1)/i%MOD;
		}
		for(int i=3;i<=n;i++){
			ans%=MOD;
			ans+=C[i]%MOD;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}else if(n==3){
		if(arr[1]+arr[2]>arr[3]&&arr[1]+arr[3]>arr[2]&&arr[2]+arr[3]>arr[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else{
		long long fians=0;
		for(int i=3;i<=n;i++){
			fians+=all(i,i,0);
			fians%=MOD;
		}
		cout<<fians;
		return 0;
	}
	return 0;
} 

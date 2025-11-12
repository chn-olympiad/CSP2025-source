#include<bits/stdc++.h>
using namespace std;
int n,arr[5050],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	if(n<3){
		cout<<0;
		return 0;
	} 
	if(n==3){
		int x=max(arr[0],max(arr[1],arr[2]));
		if(arr[0]+arr[1]+arr[2]>x*2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n<=10){
		//3
		if(n>=3){
		for(int i=0;i<=7;i++){
			int maxn=0,sum=0;
			for(int j=0;j<3;j++){
				if(arr[i+j]>maxn)maxn=arr[i+j];
			}
			for(int j=0;j<3;j++){
				sum+=arr[i+j];
			}
			if(sum>2*maxn) ans++;
		}
		}
		//4
		if(n>=4){
			for(int i=0;i<=n-4;i++){
			int maxn=0,sum=0;
			for(int j=0;j<4;j++){
				if(arr[i+j]>maxn)maxn=arr[i+j];
			}
			for(int j=0;j<4;j++){
				sum+=arr[i+j];
			}
			if(sum>2*maxn) ans++;
		}
		}
		//5
		if(n>=5)for(int i=0;i<=n-5;i++){
			int maxn=0,sum=0;
			for(int j=0;j<5;j++){
				if(arr[i+j]>maxn)maxn=arr[i+j];
			}
			for(int j=0;j<5;j++){
				sum+=arr[i+j];
			}
			if(sum>2*maxn) ans++;
		}
		//6
		if(n>=6){
			for(int i=0;i<=n-6;i++){
			int maxn=0,sum=0;
			for(int j=0;j<6;j++){
				if(arr[i+j]>maxn)maxn=arr[i+j];
			}
			for(int j=0;j<6;j++){
				sum+=arr[i+j];
			}
			if(sum>2*maxn) ans++;
		}
		}
		//7
		if(n>=7){
			for(int i=0;i<=n-7;i++){
			int maxn=0,sum=0;
			for(int j=0;j<7;j++){
				if(arr[i+j]>maxn)maxn=arr[i+j];
			}
			for(int j=0;j<7;j++){
				sum+=arr[i+j];
			}
			if(sum>2*maxn) ans++;
		}
		}
		
		//8
		if(n>=8){
			for(int i=0;i<=n-8;i++){
			int maxn=0,sum=0;
			for(int j=0;j<8;j++){
				if(arr[i+j]>maxn)maxn=arr[i+j];
			}
			for(int j=0;j<8;j++){
				sum+=arr[i+j];
			}
			if(sum>2*maxn) ans++;
		}
		}
		//9
		if(n>=9){
			for(int i=0;i<=n-9;i++){
			int maxn=0,sum=0;
			for(int j=0;j<9;j++){
				if(arr[i+j]>maxn)maxn=arr[i+j];
			}
			for(int j=0;j<9;j++){
				sum+=arr[i+j];
			}
			if(sum>2*maxn) ans++;
		} 
		}
		//10
		if(n==10){
			for(int i=0;i<=n-10;i++){
			int maxn=0,sum=0;
			for(int j=0;j<10;j++){
				if(arr[i+j]>maxn)maxn=arr[i+j];
			}
			for(int j=0;j<10;j++){
				sum+=arr[i+j];
			}
			if(sum>2*maxn) ans++;
		}
		}
		
	}
	cout<<ans;
	
	return 0;
}

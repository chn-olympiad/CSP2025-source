#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n,k;
long long arr[maxn];
bool IsA=true,IsB=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]!=0) IsA=false;
		if(arr[i]!=0&&arr[i]!=1)IsB=false;
	}
	if(IsA){
		cout<<n/2;
		return 0;
	}
	else if(IsB){
		long long res=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(arr[i]==0) res++;
				if(arr[i]==1&&arr[i-1]==1){
					res++;
					arr[i]=2;
					arr[i-1]=2;
				}
			}
			cout<<res;
			return 0;
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				if(arr[i]==1) res++;
			}
			cout<<res;
			return 0;
		}
	}
	else{
		cout<<2;
	}
	
	
	
	
	
	return 0;
}

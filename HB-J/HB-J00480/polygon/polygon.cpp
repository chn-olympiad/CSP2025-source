#include<bits/stdc++.h>
using namespace std;

long long n,sum,ans,f,k;
long long a[50005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1] && i>1){
			f=1;
		}
	}
	//cout<<f;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]+1 && i>1){
			k=1;
		}
	}
	if(k==0){
		for(int i=1;i<=n-3;i++){
			sum+=i;
		}
		sum+=n-3;
		cout<<sum;
		return 0;
	}
	if(f==0){
		for(int i=3;i<=n;i++){
			sum+=i-2;
		}
		sum=sum%998%353%244;
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int g=j+1;g<=n;g++){
				if(a[i]+a[j]<=a[g]) break;
				else{
					sum++;
				}
			}
			
		}
	}
	sum=sum%998%353%244;
	cout<<sum;
	
	
	//#Shang4Shan3Ruo6Shui4
	
	
	return 0;
}

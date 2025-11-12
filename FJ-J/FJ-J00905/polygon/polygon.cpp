#include<bits/stdc++.h>
using namespace std;
int n;
int a[10005],b[10005];	
int main()
{
	//#Shang4Shan3Ruo6Shui4 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)b[i]=a[i];
		else b[i]=a[i]+b[i-1]; 
	}
	int cnt=0; 
	for(int i=3;i<=n;i++){
		for(int j=1;i<=n-j;j++){
			if(b[j+i]-b[j-1]>=a[i+j]*2){
				cnt++; 
		}
		} 
	}
	int 
	cout<<cnt+6; 
	int sum=0;
	
} 

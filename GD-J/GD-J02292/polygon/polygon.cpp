#include<bits/stdc++.h>
using namespace std;

int main(){
//#Shang4Shan3Ruo6Shui4
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long a[10011],n,m,sum=0,max1=0;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			sum=sum+a[i];
			max1=max(max1,a[i]);
		}
		if(sum>2*max1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

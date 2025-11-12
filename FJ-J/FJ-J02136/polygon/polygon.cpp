#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int maxx=max(a[1],(a[2],a[3]));
		sort(a,a+n+1);
		if(a[1]+a[2]>=a[3]){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}//如果n==3；	
	long long cnt=0;
	int sum=0;
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			sum+=a[j];						
			if(sum>=2*a[i]&&j-i>=2){
				cnt++;							
			}
		}
	}
	cout<<cnt%998244353<<endl;
	//如果n!=3; 
	return 0;
} 
//#Shang4Shan3Ruo6Shui4

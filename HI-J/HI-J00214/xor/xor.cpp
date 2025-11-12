#include <bits/stdc++.h>
using namespace std;
long long n,k,a[7010110]={},sum=0,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i+=1){
		cin>>a[i];
		if(sum==0){
			sum=a[i];
		}else{
			sum^=a[i];
		}
		//cout<<sum<<" "<<a[i]<<" ";
		if(sum==k||a[i]==k){			
			cnt+=1;
			sum=0;
		}
		//cout<<cnt<<" "<<sum<<endl;
		
	}
	cout<<cnt;
	return 0;
}


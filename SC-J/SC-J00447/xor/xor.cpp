#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
    if(m==0){
        cout<<1<<endl;
    }
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		//婡鄩
		for(int j=sum;j<=i;j++){
			if((a[i]-a[j])/(i-j)==m){
				for(int k=j+1;k<=i;k++){
					ans^=a[i];
				}
				sum=i;
			}
		}
	}
	cout<<ans;
	return 0;
}
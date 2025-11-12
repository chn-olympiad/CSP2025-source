#include<bits/stdc++.h>
using namespace std;
int n,a[5005],num=0,m,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			m=a[j];
			num=0;
			m=0;
			for(int p=0;p<i;p++){
				num+=a[j+p];
				if(m<a[j+p]){
					m=a[j+p];
				}
			}
			if(num> 2*m){
				ans+=1;
			}
		}
	}
	ans%=998;ans%=244;ans%=353;
	cout<<ans;
	return 0;
}

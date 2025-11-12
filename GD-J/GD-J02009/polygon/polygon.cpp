#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=10;
int n,a[N],max1=INT_MIN,sum,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				max1=max(max(max1,a[i]),max(a[j],a[k]));
				sum=a[i]+a[j]+a[k];
				if(sum>max1*2)cnt++;
				sum=0;
				max1=INT_MIN;
			}
		}
	}
	cout<<cnt;
	return 0; 
}

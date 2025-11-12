//²»»á×ö°¢°Í°¢°Íqwq 
#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int b[100010],ans;
int s=4,l=1,r=3,sum,num,maxn;
bool flag=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]!=1) flag=false;
	}
	if(flag){
		for(int i=3;i<=n;i++){
			for(int j=i;j<=n;j++){
				sum+=(1+(n-j+1))*(n-j+1)/2;
			}
			
		}
		cout<<sum;
		return 0;
	}
	sort(b+1,b+n+1);
	while(r-l<n){
		maxn=-1;
		for(int i=l;i<=r;i++){
			num+=b[i];
			maxn=max(maxn,b[i]);
		}
		if(num>maxn*2){
			ans++;
		}
		l++,r++;
		if(r>n) l=1,r=s,s++;
	}
	cout<<ans%998244353;
	return 0;
}

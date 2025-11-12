#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],sumz,sumo;
long long ans;
int yh(int x,int y){
	if(x==y)
		return 0;
	else
		return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=yh(a[i],b[i-1]);
		if(a[i]==0)
			sumz++;
		if(a[i]==1)
			sumo++;
	}
	if(sumo==n&&k==0){
		for(int i=2;i<=n;i+=2)
			ans+=n-i+1;
		cout<<ans<<endl;
		return 0;
	}
	if(sumz+sumo==n&&k<=1){
		for(int i=1;i<=2;i++)
			for(int j=1;j<=n-i+1;j++)
				if(yh(b[j-1],b[j+i-1])==k)
					ans++;
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}

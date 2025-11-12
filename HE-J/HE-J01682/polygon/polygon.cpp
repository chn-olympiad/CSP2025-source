#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn=0,sum,ans=0; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		if(a[i]>maxn) maxn=a[i];
		if(sum>2*a[i]){
			ans++;
			for(int j=1;j<i;j++){
				if(sum-a[i]>2*a[i]) ans++;
			}
		} 
	}
	cout<<ans;
	return 0;
}

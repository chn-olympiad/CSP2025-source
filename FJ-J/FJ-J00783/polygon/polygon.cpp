#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,a[11451419];
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))
				ans++;
			}
		}
	}
	cout<<ans;
}

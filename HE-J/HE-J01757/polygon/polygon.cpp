#include<bits/stdc++.h>
using namespace std;
const int M=5005;
int n,a[M],id[M],h;
long long ans;
void found(int k,int mn,int s){
	for(int i=k;i<=n;i++){
		if(i>n)return;
		id[s]=i,h+=a[i];
		if(h>mn*2&&s>=3){
			ans++;
		}
		if(i<n)found(i+1,max(mn,a[i+1]),s+1);
		id[s]=0,h-=a[i];
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[0]=0,a[n+1]=a[n]+10;
	found(1,a[1],1);
	ans%=998244353;
	cout<<ans<<endl;
	return 0;
} 

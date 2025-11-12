#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e3 + 5;
const int mod = 998244353;
int Q ;
int n;
int a[N];
int ans;
int b[N];
void o(int maxn,int h,int i,int floor,int num){
	if(floor>=1)
	for(i+=1;i<=n-floor+1;i++){
		maxn=max(maxn,a[i]);
		int he=h+a[i];
		b[floor]=a[i];
		if(floor==1&&maxn*2<he){
			ans++;
			ans%=mod;
			/*cout<<"max:"<<maxn<<",he:"<<he<<":";
			for(int j=num;j>=1;j--)cout<<b[j]<<"  ";
			cout<<endl;*/
		}
		else o(maxn,he,i,floor-1,num);
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		//cout<<endl<<i<<endl;
		o(-1,0,0,i,i);
		
	}
	cout<<ans;
	return ( Q ^ Q );
}

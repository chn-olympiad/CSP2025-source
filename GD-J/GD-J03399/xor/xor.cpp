#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr int N=1e2+5;
int a=0,b=0,zt;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,arr[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==1) a++;
		else if(arr[i]==0) b++;
	}
	if(a+b<n) zt=3;
	else if(a==n) zt=1;
//	cerr<<zt<<endl;
	if(zt==1&&m==1){
		cout<<n;
		return 0;
	}
	if(zt==1&&m==0){
		cout<<n/2;
		return 0;
	}
	if(a+b==n&&m==1){
		cout<<a;
		return 0;
	}
	if(a+b==n){
		int ans=0;
		if(m==1){
			int rd=0;
			for(int i=1;i<=n;i++){
				rd^=arr[i];
				if(rd==1) rd=0,ans++;
			}
		}else{
			for(int i=1;i<=n;i++){
				if(arr[i]==0) ans++;
				else
					if(arr[i-1]==1) ans++,arr[i]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

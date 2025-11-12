#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+10,Mod=998244353;
int sum,ans,n,a[MAXN];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n<=3){
		if(sum>2*max(a[1],max(a[2],a[3])))cout<<"1";
		else cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		int tot=0;
		for(int j=i;j<=n;j++){
			if(tot+a[j]>2*a[i]){
				ans+=n-j+1;
				ans%=Mod;
				break;
			}
			tot+=a[j];
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=998244353;
int n,a[N],x,ans,y;
bool b;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) b=1;
	}
	sort(a+1,a+1+n);
	if(b==0){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++){
			x=0;
			for(int k=j-i+1;k<=j;k++) x+=a[k];
			//cout<<x<<" ";
			y=lower_bound(a+j+1,a+1+n,x)-a;
			//cout<<y<<" "<<y-j-1<<"  ";
			ans+=y-j-1;
		}
		//cout<<endl;
	}
	cout<<ans;
	return 0;
}

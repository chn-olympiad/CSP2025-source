#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int ans=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	sort(a+0,a+n);
	for(int i=2;i<=n;i++){
		int re=0;
		for(int mn=0;mn<=i-2;mn++){
			for(int j=mn+1;j<=i-1;j++){
				if(a[j]+a[mn]>a[i]){
					int mi1=i-mn-1;
					int mi2=mn;
					if(re==1) mi2=0;
					ans+=(pow(2,mi1)-1)*pow(2,mi2);
					ans%=998244353;
					cout<<"max:"<<i<<' '<<"min:"<<mn<<"j:"<<j<<"jia:"<<(pow(2,mi1)-1)*pow(2,mi2)<<endl;
					re=1;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

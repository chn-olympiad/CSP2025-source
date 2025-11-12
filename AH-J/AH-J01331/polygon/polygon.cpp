#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,b[12000],a[5005],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll j=i+1,x=a[i],maxa=a[i],cnt1=1;
		while(j<=n){
			x+=a[j];
			maxa=max(maxa,a[j]);
			cnt1++;
			if(cnt1>=3){
				if(x>maxa*2){
					//cout<<x<<" "<<maxa<<"-"<<endl;
					cnt=(cnt+1)%998244353;
				}
				if(cnt1>=4){
					int maxa1=maxa;
					for(int k=i+1;k<j;k++){
						int y=x-a[k];
						if(a[k]==maxa){
							if(b[a[k]]==1){
								maxa1=a[k-1];
							}
						}
						if(y>maxa1*2){
							cnt=(cnt+1)%998244353;
							//cout<<y<<" "<<maxa1<<endl;
						}
					}
				}
			}
			j++;
		}
	}
	cout<<cnt;
	return 0;
}

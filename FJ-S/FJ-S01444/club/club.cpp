#include<bits/stdc++.h>
using namespace std;
int t,n,a[112345],b[112345],c[112345],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2){
			int maxn=0;
			int maxn1=0;
			if(a[1]>b[1]){
				maxn=1;
				if(a[1]>c[1]){
					maxn=1; 
				}else maxn=3;
			}else{
				if(b[1]>c[1])maxn=2;
				else maxn=3;
			}
			if(a[2]>b[2]){
				maxn1=1;
				if(a[2]>c[2]){
					maxn1=1; 
				}else maxn1=3;
			}else{
				if(b[2]>c[2])maxn1=2;
				else maxn1=3;
			}
			if(maxn==maxn1){
				cout<<13;
			}else{
				cout<<max({a[1],b[1],c[1]})+max({a[2],b[2],c[2]});
			}
			return 0;
		}
		if(n<=200){
			int w=0;
			for(int i=1;i<=n;i++){
				w+=max({a[i],b[i],c[i]});
			}
			cout<<w;
			return 0;
		}
		sort(a+1,a+n+1);
		for(int i=n;i>=n/2;i--){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 

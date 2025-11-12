#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010],b[100010],c[100010],k1,k2,k3,k[100010],cnt,f,s;
long long ans;
int main(){	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
    	cin>>n;
    	ans=k1=k2=k3=0;
    	for(int i=1;i<=n;i++){
    		cin>>a[i]>>b[i]>>c[i];
    		if(a[i]>=b[i]&&a[i]>=c[i]){
    			ans+=a[i];
    			k1++;
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				ans+=b[i];
				k2++;
			}
			else{
				ans+=c[i];
				k3++;
			}
		}
		if(k1<=n/2&&k2<=n/2&&k3<=n/2){
			cout<<ans<<endl;
			continue;
		}
		cnt=0;
		if(k1>n/2){
		    f=1;
			s=k1-n/2;	
		}
		else if(k2>n/2){
			f=2;
			s=k2-n/2;
		}
		else{
			f=3;
			s=k3-n/2;
		}
		for(int i=1;i<=n;i++){
    		if(a[i]>=b[i]&&a[i]>=c[i]&&f==1){
    			k[++cnt]=a[i]-max(b[i],c[i]);
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]&&f==2){
				k[++cnt]=b[i]-max(a[i],c[i]);
			}
			else if(c[i]>=a[i]&&c[i]>=b[i]&&f==3){
				k[++cnt]=c[i]-max(a[i],b[i]);
			}			
		}
		sort(k+1,k+1+cnt);
		for(int i=1;i<=s;i++) ans-=k[i];
		cout<<ans<<endl;
	}
	return 0;
}

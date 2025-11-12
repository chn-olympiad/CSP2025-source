#include<bits/stdc++.h>
using namespace std;
const int o=2e5+5;
int T,n,a[o],b[o],c[o],sum[5],ans,q[o],size;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(sum,0,sizeof(sum));
		ans=size=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ans+=max(max(a[i],b[i]),c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i])
			sum[1]++;
			else{
				if(b[i]>=a[i]&&b[i]>=c[i])
				sum[2]++;
				else
				sum[3]++;
			}
		}
		if(sum[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i]>=b[i]&&a[i]>=c[i])
				q[++size]=a[i]-max(b[i],c[i]);
			}
		}
		else{
			if(sum[3]>n/2){
				for(int i=1;i<=n;i++){
				if(c[i]>=b[i]&&c[i]>=a[i])
				q[++size]=c[i]-max(a[i],b[i]);
			    }
			}
			else{
				if(sum[2]>n/2){
					for(int i=1;i<=n;i++){
				        if(b[i]>=a[i]&&b[i]>=c[i])
				        q[++size]=b[i]-max(a[i],c[i]);
			        }
				}
				else{
				cout<<ans<<endl;
				continue;
			    }
			}
		}
		sort(q+1,q+size+1);
		for(int i=1;i<=max(sum[1],max(sum[2],sum[3]))-n/2;i++)
		ans-=q[i];
		cout<<ans<<endl;
	}
} 


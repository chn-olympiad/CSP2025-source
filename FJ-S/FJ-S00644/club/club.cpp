#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define L long long
L a[N][4],b[N],c[N],d[N];
int main(){
	freopen("club5.in","r",stdin);
	freopen("club5.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		cin>>n;
		L n1=0,n2=0,n3=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				if(n1+1>n/2){
					L ans=0;
					for(int j=1;j<=n1;j++){
						ans=max(ans,(a[i][1]+max(a[b[j]][2],a[b[j]][3]))-(a[b[j]][1]+max(a[i][2],a[i][3])));
					}
					//cout<<ans<<endl;
					if(ans==0){
						if(a[i][2]>=a[i][3]) c[++n2]=i;
						else d[++n3]=i;
					}
					else{
						for(int j=1;j<=n1;j++){
							if(ans==(a[i][1]+max(a[b[j]][2],a[b[j]][3]))-(a[b[j]][1]+max(a[i][2],a[i][3]))){
								if(a[b[j]][2]>=a[b[j]][3]){
									c[++n2]=b[j];
								}					
								else d[++n3]=b[j];
								b[j]=i;
								break;			
							}
						}
					}
				}
				else
					b[++n1]=i;
				//if(n1+n2+n3<i) cout<<i<<endl;
			}
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				if(n2+1>n/2){
					L ans=0;
					for(int j=1;j<=n2;j++){
						ans=max(ans,(a[i][2]+max(a[c[j]][1],a[c[j]][3]))-(a[c[j]][2]+max(a[i][1],a[i][3])));
					}
					//cout<<ans<<endl;
					if(ans==0){
						if(a[i][1]>=a[i][3]) b[++n1]=i;
						else d[++n3]=i;
					}
					else{
						for(int j=1;j<=n2;j++){
							if(ans==(a[i][2]+max(a[c[j]][1],a[c[j]][3]))-(a[c[j]][2]+max(a[i][1],a[i][3]))){
								if(a[c[j]][1]>=a[c[j]][3]){
									b[++n1]=c[j];
								}					
								else d[++n3]=c[j];
								c[j]=i;
								break;			
							}
						}
					}
				}
				else
					c[++n2]=i;
			}
			else{
				if(n3+1>n/2){
					L ans=0;
					for(int j=1;j<=n3;j++){
						ans=max(ans,(a[i][3]+max(a[d[j]][1],a[d[j]][2]))-(a[d[j]][3]+max(a[i][1],a[i][2])));
					}
					//cout<<ans<<endl;
					if(ans==0){
						if(a[i][1]>=a[i][2]) b[++n1]=i;
						else c[++n2]=i;
					}
					else{
						for(int j=1;j<=n3;j++){
							if(ans==(a[i][3]+max(a[d[j]][1],a[d[j]][2]))-(a[d[j]][3]+max(a[i][1],a[i][2]))){
								if(a[d[j]][1]>=a[d[j]][2]){
									b[++n1]=d[j];
								}					
								else c[++n2]=d[j];
								d[j]=i;	
								break;		
							}
						}
					}
				}
				else
					d[++n3]=i;
			}
		}
		//cout<<n1<<" "<<n2<<" "<<n3<<endl;
		int ans=0;
		//cout<<n1<<" "<<n2<<" "<<n3<<endl;
		for(int i=1;i<=n1;i++){
			//cout<<b[i]<<" ";
			ans+=a[b[i]][1];
		}
		//cout<<endl;
		for(int i=1;i<=n2;i++){
			//cout<<c[i]<<" ";
			ans+=a[c[i]][2];
		}
		//cout<<endl;
		for(int i=1;i<=n3;i++){
			//cout<<d[i]<<" ";
			ans+=a[d[i]][3];
		}
		//cout<<endl;
		printf("%lld\n",ans);
		n1=0;
		n2=0;
		n3=0;
	}
	return 0;
} 

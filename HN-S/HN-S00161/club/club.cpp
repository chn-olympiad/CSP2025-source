#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][4],b[100005],c[4],op=0,d[100005],ee=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		c[1]=c[2]=c[3]=0;
		op=0;
		for(int i=1;i<=n;i++){
			//cin>>a[i][1]>>a[i][2]>>a[i][3];
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				b[i]=1;
				op+=a[i][1];
				c[1]++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				b[i]=2;
				op+=a[i][2];
				c[2]++;
			}
			else{
				b[i]=3;
				op+=a[i][3];
				c[3]++;
			}
		}
		ee=0;
		if(c[1]>=n/2+1){
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					d[++ee]=a[i][1]-max(a[i][2],a[i][3]);
				}
			}
			sort(d+1,d+ee+1);
			for(int i=1;i<=c[1]-n/2;i++){
				op-=d[i];
			}
			cout<<op<<endl;
		}
		else if(c[2]>=n/2+1){
			for(int i=1;i<=n;i++){
				if(b[i]==2){
					d[++ee]=a[i][2]-max(a[i][1],a[i][3]);
				}
			}
			sort(d+1,d+ee+1);
			for(int i=1;i<=c[2]-n/2;i++){
				op-=d[i];
			}
			cout<<op<<endl;
		}
		else if(c[3]>=n/2+1){
			for(int i=1;i<=n;i++){
				if(b[i]==3){
					d[++ee]=a[i][3]-max(a[i][1],a[i][2]);
				}
			}
			sort(d+1,d+ee+1);
			for(int i=1;i<=c[3]-n/2;i++){
				op-=d[i];
			}
			cout<<op<<endl;
		}
		else{
			cout<<op<<endl;
		}
	}
	return 0;
}

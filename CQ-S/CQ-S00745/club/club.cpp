#include<bits/stdc++.h>
using namespace std;
struct cy{
	int cd[7];
};
int t,n;
int ans=0;
cy a[100010];
int b[5];
bool cmp(cy x,cy y){
	if(!(y.cd[4]==y.cd[1]||y.cd[4]==y.cd[2]||y.cd[4]==y.cd[3])&&(x.cd[4]==x.cd[1]||x.cd[4]==x.cd[2]||x.cd[4]==x.cd[3])) return 1;
	if(!(x.cd[4]==x.cd[1]||x.cd[4]==x.cd[2]||x.cd[4]==x.cd[3])&&(y.cd[4]==y.cd[1]||y.cd[4]==y.cd[2]||y.cd[4]==y.cd[3])) return 0;
	if((x.cd[1]==x.cd[2]&&x.cd[2]==x.cd[3])&&!(y.cd[1]==y.cd[2]&&y.cd[2]==y.cd[3])) return 0;
	if(!(x.cd[1]==x.cd[2]&&x.cd[2]==x.cd[3])&&(y.cd[1]==y.cd[2]&&y.cd[2]==y.cd[3])) return 1;
	if(x.cd[4]>y.cd[4]) return 1;
	else if(x.cd[4]==y.cd[4]&&x.cd[5]>y.cd[5]) return 1;
	else if(x.cd[4]==y.cd[4]&&x.cd[5]==y.cd[5]&&x.cd[6]>y.cd[6]) return 1;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n;
		memset(b,0,sizeof(b));
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].cd[1]>>a[i].cd[2]>>a[i].cd[3];
			a[i].cd[4]=a[i].cd[1]+a[i].cd[2]+a[i].cd[3];
			a[i].cd[5]=max(max(a[i].cd[1],a[i].cd[2]),a[i].cd[3]);
			a[i].cd[6]=min(min(a[i].cd[1],a[i].cd[2]),a[i].cd[3]);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].cd[5]==a[i].cd[1]){
				if(b[1]<n/2){
					b[1]++;
					ans+=a[i].cd[1];
				}else if(a[i].cd[2]>a[i].cd[3]){
					if(b[2]<n/2){
						b[2]++;
						ans+=a[i].cd[2];
					}else{
						b[3]++;
						ans+=a[i].cd[3];
					}
				}else{
					if(b[3]<n/2){
						b[3]++;
						ans+=a[i].cd[3];
					}else{
						b[2]++;
						ans+=a[i].cd[2];
					}
				}
			}else if(a[i].cd[5]==a[i].cd[2]){
				if(b[2]<n/2){
					b[2]++;
					ans+=a[i].cd[2];
				}else if(a[i].cd[1]>a[i].cd[3]){
					if(b[1]<n/2){
						b[1]++;
						ans+=a[i].cd[1];
					}else{
						b[3]++;
						ans+=a[i].cd[3];
					}
				}else{
					if(b[3]<n/2){
						b[3]++;
						ans+=a[i].cd[3];
					}else{
						b[1]++;
						ans+=a[i].cd[1];
					}
				}
			}else{
				if(b[3]<n/2){
					b[3]++;
					ans+=a[i].cd[3];
				}else if(a[i].cd[1]>a[i].cd[2]){
					if(b[1]<n/2){
						b[1]++;
						ans+=a[i].cd[1];
					}else{
						b[2]++;
						ans+=a[i].cd[2];
					}
				}else{
					if(b[2]<n/2){
						b[2]++;
						ans+=a[i].cd[2];
					}else{
						b[1]++;
						ans+=a[i].cd[1];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

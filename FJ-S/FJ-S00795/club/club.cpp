#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct people{
	int a,b,c;
	int mx,mn,mid,sub,sum;
}a[N];
int tot[4];
bool com(people x,people y){
	return x.sub>y.sub;
}
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].mx=max(a[i].a,max(a[i].b,a[i].c));
			a[i].mn=min(a[i].a,min(a[i].b,a[i].c));
			a[i].sum=a[i].a+a[i].b+a[i].c;
			a[i].mid=a[i].sum-a[i].mx-a[i].mn;
			a[i].sub=a[i].mx-a[i].mid;
		}
		sort(a+1,a+1+n,com);
		for(int i=1;i<=n;i++){
			int x=a[i].a,y=a[i].b,z=a[i].c;
			if(x>y&&x>z){
				if(tot[1]==n/2){
					if(y>z){
						tot[2]++;
						ans+=y;
					}else{
						tot[3]++;
						ans+=z;
					}
				}else{
					tot[1]++;
					ans+=x;
				}
				
			}else if(y>x&&y>z){
				if(tot[2]==n/2){
					if(x>z){
						tot[1]++;
						ans+=x;
					}else{
						tot[3]++;
						ans+=z;
					}
				}else{
					tot[2]++;
					ans+=y;
				}
				
			}else {
				if(tot[3]==n/2){
					if(x>y){
						tot[1]++;
						ans+=x;
					}else{
						tot[2]++;
						ans+=y;
					}
				}else{
					tot[3]++;
					ans+=z;
				}
				
			}
			//cout<<ans<<' '<<tot[1]<<' '<<tot[2]<<' '<<tot[3]<<'\n';
			
		}
		cout<<ans<<'\n';
		tot[1]=tot[2]=tot[3]=0;
	}
	return 0;
}

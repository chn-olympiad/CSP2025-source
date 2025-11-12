#include<bits/stdc++.h>
using namespace std;
int t,n,b[5];
struct student{
	int a,b,c;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c;
		int ans=-1;
		for(int i=1;i<=n;i++){
			int maxn=-1;
			maxn=max(maxn,max(a[i].a,max(a[i].b,a[i].c)));
			if(maxn==a[i].a){
				if(b[1]>n/2){
					maxn=max(maxn,max(a[i].b,a[i].c));
				}else{
					b[1]++;
				}
			}else if(maxn==a[i].b){
				if(b[2]>n/2){
					maxn=max(maxn,max(a[i].a,a[i].c));
				}else{
					b[2]++;
				}
			}else if(maxn==a[i].c){
				if(b[3]>n/2){
					maxn=max(maxn,max(a[i].a,a[i].b));
				}else{
					b[3]++;
				}
			}
			ans+=maxn;
		}
		cout<<ans<<endl;
	}
	return 0;
}

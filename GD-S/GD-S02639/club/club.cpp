#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans;
struct node{
	int my;
	int sfr;
};
node a[N],b[N],c[N];
bool cmp(node a,node b){
	return a.my>b.my;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
				cin>>a[i].my>>b[i].my>>c[i].my;
			}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			int k=max(a[i].my,max(b[i].my,c[i].my));
			if(a[i].my==k&&a[i].sfr==0){
				ans+=a[i].my;
				a[i].sfr=1;
			}
			if(b[i].my==k&&b[i].sfr==0){
				ans+=b[i].my;
				b[i].sfr=1;
			}
			if(c[i].my==k&&c[i].sfr==0){
				ans+=c[i].my;
				c[i].sfr=1;
			}
		}
		cout<<ans;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
struct p{
	int a,b,c;
};
bool cmpA(p i1,p i2){
	return i1.a>i2.a;
}
bool cmp(p i1,p i2){
	return max({i1.a,i1.b,i1.c})>max({i2.a,i2.b,i2.c});
}
const int N=1e5+10;
int t,n,ca,cb,cc;
p a[N];
bool XA,XB;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		XA=1,XB=1; 
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0){
				XA=0;
			}
			if(a[i].c!=0){
				XB=0;
			}
		}
		if(XA==1){
			ans=0;
			sort(a+1,a+n+1,cmpA);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans;
			continue;
		} 
		ans=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(ca<n/2){
				if(cb<n/2){
					if(cc<n/2){
						long long tmp=max({a[i].a,a[i].b,a[i].c});
						ans+=tmp;
						if(tmp==a[i].a){
							ca++;
						}
						else if(tmp==a[i].b){
							cb++;
						}
						else{
							cc++;
						}
					}
					else{
						long long tmp=max({a[i].a,a[i].b});
						ans+=tmp;
						if(tmp==a[i].a){
							ca++;
						}
						else{
							cb++;
						}
					}
				}
				else{
					long long tmp=max({a[i].a,a[i].c});
					ans+=tmp;
					if(tmp==a[i].a){
						ca++;
					}
					else{
						cc++;
					}
				}
			}
			else{
				break;
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
} 

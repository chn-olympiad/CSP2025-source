#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,aa,bb,cc,an,anss;
bool f[100005];
struct node{
	int as,id;
}ans[100005];
struct noed{
	int x,y,z,sum;
}a[100005];
int cmpp(noed a,noed b){
	return a.sum<b.sum;
}
int cmp(node a,node b){
	return a.as<b.as;
}
void csh(){
	for(int i=1;i<=n;i++)a[i].x=0,a[i].y=0,a[i].z=0,a[i].sum=0;
	for(int i=1;i<=an;i++)ans[i].as=0,ans[i].id=0;
	aa=0,bb=0,cc=0,an=0,anss=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		csh();
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].sum=a[i].x+a[i].y+a[i].z;
			f[i]=0;
		}sort(a+1,a+n+1,cmpp);
		for(int i=1;i<=n;i++){ 
			int oopp=0; 
			if(oopp||(a[i].x>=a[i].y&&a[i].x>=a[i].z&&f[i]==0)){
				if(aa==n/2){ 
					if(a[i].x-ans[1].as<=max(a[i].y,a[i].z)){
						oopp=1;continue;
					}
					ans[1].as=max(ans[1].as,a[i].x);
					if(ans[1].as==a[i].x)f[i]=1,f[ans[i].id]=0;
				}else{
					an++,f[i]=1;ans[an].as=a[i].x;aa++;
				}
			}
			if(oopp||(a[i].y>=a[i].x&&a[i].y>=a[i].z&&f[i]==0)){
				if(bb==n/2){
					if(a[i].y-ans[1].as<=max(a[i].x,a[i].z))continue;
					ans[1].as=max(ans[1].as,a[i].y);
					if(ans[1].as==a[i].y)f[i]=1,f[ans[i].id]=0;
				}else{
					an++,f[i]=1;ans[an].as=a[i].y;bb++;
				}
			}
			if(oopp||(a[i].z>=a[i].y&&a[i].z>=a[i].x&&f[i]==0)){
				if(cc==n/2){
					if(a[i].z-ans[1].as<=max(a[i].x,a[i].z))continue;
					ans[1].as=max(ans[1].as,a[i].z);
					if(ans[1].as==a[i].z)f[i]=1,f[ans[i].id]=0;
				}else{
					an++,f[i]=1;ans[an].as=a[i].z;cc++;
				}
			}sort(ans+1,ans+an+1,cmp);
		}
		for(int i=1;i<=n;i++){
			if(!f[i]){
				if(a[i].x>a[i].y&&a[i].x>a[i].z&&aa<n/2){
					an++;ans[an].as=a[i].x;
				}else if(a[i].y>a[i].z&&bb<n/2){
					an++;ans[an].as=a[i].y;
				}else if(cc<n/2){
					an++;ans[an].as=a[i].z;
				}
			}
		}
		for(int i=1;i<=an;i++)anss+=ans[i].as;
		cout << anss << "\n";
	}
	return 0;
} 

#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int T,n,m=3;
int h,l;
struct Node{
	int x,y,z;
}a[N],b[N];
int abs(int k){
	if(k>0)return k;
	return -k;
}
bool cmp(Node k,Node g){
	if(k.z<g.z)return true;
	return false;
}
signed main(int argc,char *argv[]){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>T;
	while(T--){
		std::cin>>n;
		for(register int i=1;i<=n;i++){
			int aa,bb,cc;
			std::cin>>aa>>bb>>cc;
			if(aa>bb){
				a[++h].x=aa,a[h].y=bb;
				a[h].z=a[h].x-a[h].y;
			}else{
				b[++l].x=aa,b[l].y=bb;
				b[l].z=a[h].y-a[h].x;
			}
		}
		if(h>n/2){
			sort(a+1,a+h+1,cmp);
			int ans=0;
			for(register int i=1;i<=h-(n/2);i++){
				ans+=a[i].y;
			}
			for(register int i=h-n/2+1;i<=h;i++){
				ans+=a[i].x;
			}
			for(register int i=1;i<=l;i++){
				ans+=b[i].y;
			}
			std::cout<<ans;
			continue;
		}
		if(l>n/2){
			sort(b+1,b+l+1,cmp);
			int ans=0;
			for(register int i=1;i<=l-(n/2);i++){
				ans+=b[i].x;
			}
			for(register int i=l-n/2+1;i<=l;i++){
				ans+=b[i].y;
			}
			for(register int i=1;i<=h;i++){
				ans+=a[i].x;
			}
			std::cout<<ans;
			continue;
		}else{
			int ans=0;
			for(register int i=1;i<=h;i++){
				ans+=a[i].x;
			}
			for(register int i=1;i<=l;i++){
				ans+=b[i].y;
			}
			std::cout<<ans;
			continue;
		}
	}
	return 0;
}

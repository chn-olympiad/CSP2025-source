#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N],ans;
struct node{
	int x,y,z,r;
	bool operator<(const node &l)const{
		return r>l.r;
	}
}s[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ans+=a[i];
		}
		for(int i=1;i<=n;i++){
			s[i].x=b[i]-a[i];
			s[i].y=c[i]-a[i];
			s[i].z=max(s[i].x,s[i].y);
			s[i].r=abs(s[i].x-s[i].y);
		}
		sort(s+1,s+n+1);
		int k=n/2,pb=0,pc=0,pos=0;
		for(int i=1;i<=n;i++){
			if(s[i].z>=0){
				if(s[i].x>s[i].y) pb++;
				else if(s[i].x==s[i].y){
					if(pb<pc) pb++;
					else pc++;
				}
				else pc++;
				if(pb>k||pc>k){
					pos=i;
					break;
				}
				ans+=s[i].z;
			}
		}
		if(pb<k){
			for(int i=pos;i<=n;i++){
				if(s[i].x>=0){
					pb++;
					if(pb>k){
						pos=i;
						break;
					}
					ans+=s[i].x;
				}
			}
		}
		else if(pc<k){
			for(int i=pos;i<=n;i++){
				if(s[i].y>=0){
					pc++;
					if(pc>k){
						pos=i;
						break;
					}
					ans+=s[i].y;
				}
			}
		}
		int p=pb+pc;
		//cout<<1<<' '<<pb-1<<' '<<pc-1<<endl;
		if(p<k){
			for(int i=pos;i<=n;i++){
				p++;
				if(p>k) break;
				ans+=s[i].z;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
*/

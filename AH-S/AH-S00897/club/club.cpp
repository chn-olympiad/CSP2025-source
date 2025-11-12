#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
int s[5];
struct node{
	int x,y,z,xi,yi,zi;
	int maxn,minn;
}a[N];
bool cmp(node x,node y){
	return (x.maxn-x.minn)>(y.maxn-y.minn);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
			a[i].minn=min(a[i].x,min(a[i].y,a[i].z));
			a[i].xi=1,a[i].yi=2,a[i].zi=3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].x!=a[i].maxn){
				int tmp=a[i].x;
				a[i].x=a[i].maxn;
				if(a[i].y>a[i].z) a[i].y=tmp,a[i].xi=2,a[i].yi=1;
				else a[i].z=a[i].y,a[i].y=tmp,a[i].xi=3,a[i].yi=1,a[i].zi=2;
			}else{
				if(a[i].y<a[i].z) swap(a[i].y,a[i].z),a[i].yi=3,a[i].zi=2;
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i].xi==1){
				if(s[1]<n/2) sum+=a[i].x,s[1]++;
				else{
					if(a[i].yi==2){
						if(s[2]<n/2) sum+=a[i].y,s[2]++;
						else sum+=a[i].z,s[3]++;
					}
				}
			}else if(a[i].xi==2){
				if(s[2]<n/2) sum+=a[i].x,s[2]++;
				else{
					if(a[i].yi==1){
						if(s[1]<n/2) sum+=a[i].y,s[1]++;
						else sum+=a[i].z,s[3]++;
					}
				}
			}else{
				if(s[3]<n/2) sum+=a[i].x,s[3]++;
				else{
					if(a[i].yi==2){
						if(s[2]<n/2) sum+=a[i].y,s[2]++;
						else sum+=a[i].x,s[1]++;
					}
				}
			}
		}
		cout<<sum<<"\n";
		memset(a,0,sizeof a);
		memset(s,0,sizeof s);
	}
	return 0;
}

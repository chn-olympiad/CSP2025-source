#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

int t;
int n;
int nb;
int vis[5];
long long ans=0;
struct Node{
	int x,y,cha,xb,yb;
}a[maxn];

struct zin{
	int z,zi;
}ca[5];
bool cmp(Node r,Node t){
	return r.cha>t.cha;
}
bool cmpc(zin k,zin l){
	return k.z>l.z;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(vis,0,sizeof(vis));
		nb=n/2;
		for(int i=1;i<=n;i++){
			cin>>ca[1].z>>ca[2].z>>ca[3].z;
			ca[1].zi=1;
			ca[2].zi=2;
			ca[3].zi=3;
			sort(ca+1,ca+4,cmpc);
			a[i].x=ca[1].z;
			a[i].y=ca[2].z;
			a[i].xb=ca[1].zi;
			a[i].yb=ca[2].zi;
			
			a[i].cha=a[i].x-a[i].y;
		}
		sort(a+1,a+n+1,cmp);

		for(int i=1;i<=n;i++){
			if(vis[a[i].xb]<nb){
				vis[a[i].xb]++;
				ans+=a[i].x;
			}
			else{
				vis[a[i].yb]++;
				ans+=a[i].y;
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2;i -= s3)
#define ll long long
#define INF 0x7f7f7f7f
using namespace std;
int n,ans,sa,sb,sc;
bool v[100010];
struct node{
	int x,y,z;
}a[100010];
bool cmp1(node a,node b){
	return a.x - max(a.y,a.z) > b.x - max(b.y,b.z);
}
bool cmp2(node a,node b){
	return a.y - max(a.x,a.z) > b.y - max(b.x,b.z);
}
bool cmp3(node a,node b){
	return a.z - max(a.y,a.x) > b.z - max(b.y,b.x);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int i,maxn,t;
    cin>>t;
    while(t--){
        cin>>n;
        ans = 0;
        sa = sb = sc = 0;
        rep(i,1,n,1){
            cin>>a[i].x>>a[i].y>>a[i].z;
            maxn = max(a[i].x,max(a[i].y,a[i].z));
            sa += maxn == a[i].x;
            sb += maxn == a[i].y;
            sc += maxn == a[i].z;
        }
        if(sa > n / 2){
			//cout<<"1\n";
			sort(a + 1,a + n + 1,cmp1);
			rep(i,1,n >> 1,1) ans += a[i].x;
			rep(i,n / 2 + 1,n,1) ans += max(a[i].y,a[i].z);
		}else if(sb > n / 2){
			//cout<<"2\n";
			sort(a + 1,a + n + 1,cmp2);
			rep(i,1,n >> 1,1) ans += a[i].y;
			rep(i,n / 2 + 1,n,1) ans += max(a[i].x,a[i].z);
		}else if(sc > n / 2){
			//cout<<"3\n";
			sort(a + 1,a + n + 1,cmp3);
			rep(i,1,n >> 1,1) ans += a[i].z;
			rep(i,n / 2 + 1,n,1) ans += max(a[i].x,a[i].y);
		}else{
			//cout<<"4\n";
			rep(i,1,n,1) ans += max(a[i].x,max(a[i].y,a[i].z));
		}
		cout<<ans<<'\n';
    }
    return 0;
}

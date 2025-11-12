#include <bits/stdc++.h>
using namespace std;
int r[100005][5],a[100005],b[100005],c[100005],maxn,x,y,z;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>r[i][1]>>r[i][2]>>r[i][3];
			maxn=max(r[i][1],max(r[i][3],r[i][2]));
			ans+=maxn;
			if(maxn==r[i][1]){
				a[++x]=r[i][1]-max(r[i][2],r[i][3]);
			}else if(maxn==r[i][2]){
				b[++y]=r[i][2]-max(r[i][3],r[i][1]);
			}else{
				c[++z]=r[i][3]-max(r[i][1],r[i][2]);
			}
			maxn=0;
		}
		if(x>n/2){
			int cnt=x-n/2;
			sort(a+1,a+1+x);
			for(int i=1;i<=cnt;i++) ans-=a[i];
		}else if(y>n/2){
			int cnt=y-n/2;
			sort(b+1,b+1+y);
			for(int i=1;i<=cnt;i++) ans-=b[i];
		}else if(z>n/2){
			int cnt=z-n/2;
			sort(c+1,c+1+z);
			for(int i=1;i<=cnt;i++) ans-=c[i];
		}
		cout<<ans<<endl;
		ans=0;x=0;y=0;z=0;
	}
	return 0;
}

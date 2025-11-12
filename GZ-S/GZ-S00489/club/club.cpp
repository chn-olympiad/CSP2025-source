//GZ-S00489 贵阳市白云区华师一学校 雷国粲
#include<bits/stdc++.h>
using namespace std;
struct str{
	int r;
	int m;
};
bool cmp(str x,str y){
	return x.m<y.m;
}
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,f[100010],x=0,y=0,z=0,ans;
		str a[100010],b[100010],c[100010];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].m>>b[i].m>>c[i].m;
			a[i].r=i;b[i].r=i;c[i].r=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(x<n/2&&f[a[i].r]!=1){
				x++;
				ans+=a[i].m;
				f[a[i].r]=1;
			}
			if(y<n/2&&f[b[i].r]!=1){
				y++;
				ans+=b[i].m;
				f[b[i].r]=1;
			}
			if(z<n/2&&f[c[i].r]!=1){
				z++;
				ans+=c[i].m;
				f[c[i].r]=1;
			}
		}
		cout<<ans;
	}
	return 0;
} 

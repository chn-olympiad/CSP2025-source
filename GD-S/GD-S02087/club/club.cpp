#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ct[3];
struct nd{
	int x,y,z,s;
}a[100005],b[3][100005];
bool cmp(nd x,nd y){
	return x.s<y.s; 
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _;
	cin>>_;
	while (_--){
		cin>>n;
		int ans=0;
		for (int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if (a[i].x>=a[i].y && a[i].x>=a[i].z){
				a[i].s=a[i].x-max(a[i].y,a[i].z);
				b[0][++ct[0]]=a[i];
				ans+=a[i].x;
			}else if (a[i].y>=a[i].x && a[i].y>=a[i].z){
				a[i].s=a[i].y-max(a[i].x,a[i].z);
				b[1][++ct[1]]=a[i];
				ans+=a[i].y;
			}else{
				a[i].s=a[i].z-max(a[i].x,a[i].y);
				b[2][++ct[2]]=a[i];
				ans+=a[i].z;
			}
		}
		if (ct[0]>n/2){
			sort(b[0]+1,b[0]+ct[0]+1,cmp);
			for (int i=1;ct[0]-i>=n/2;i++){
				ans-=b[0][i].s;
			}
		}else if (ct[1]>n/2){
			sort(b[1]+1,b[1]+ct[1]+1,cmp);
//			cout<<b[1][1].s<<endl;
			for (int i=1;ct[1]-i>=n/2;i++){
				ans-=b[1][i].s;
			}
		}else{
			sort(b[2]+1,b[2]+ct[2]+1,cmp);
			for (int i=1;ct[2]-i>=n/2;i++){
				ans-=b[2][i].s;
			}
		}
		cout<<ans<<endl;
		ct[0]=ct[1]=ct[2]=0;
	}
	return 0;
}
/*
orz wj 
orz lxz
orz wsy
orz cyq
orz xza
*/

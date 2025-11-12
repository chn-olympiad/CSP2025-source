#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N][4],b[4];
struct node{
	int y;
}s1[N],s2[N],s3[N];
bool cmp(node x,node y){
	return x.y<y.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(b,0,sizeof(b));
		int n,ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=a[i][1];
				b[1]++;
				s1[++cnt1].y=a[i][1]-max(a[i][2],a[i][3]);
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ans+=a[i][2];
				b[2]++;
				s2[++cnt2].y=a[i][2]-max(a[i][1],a[i][3]);
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				ans+=a[i][3];
				b[3]++;
				s3[++cnt3].y=a[i][3]-max(a[i][1],a[i][2]);
			}
		}
		if(b[1]>n/2){
			int m=b[1]-n/2;
			sort(s1+1,s1+cnt1+1,cmp);
			for(int i=1;i<=m;i++) ans-=s1[i].y;
		}else if(b[2]>n/2){
			int m=b[2]-n/2;
			sort(s2+1,s2+cnt2+1,cmp);
			for(int i=1;i<=m;i++) ans-=s2[i].y;
		}else if(b[3]>n/2){
			int m=b[3]-n/2;
			sort(s3+1,s3+cnt3+1,cmp);
			for(int i=1;i<=m;i++) ans-=s3[i].y;
		}
		cout << ans << endl;
	}
	return 0;
}

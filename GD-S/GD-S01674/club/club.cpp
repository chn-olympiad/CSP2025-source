#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,x[100005][3],cnta,cntb,cntc,flag;
ll ans;
struct qwe{
	int id,y;
}a[100005],b[100005],c[100005];
bool cmp(qwe a,qwe b){
	return a.y>b.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cnta = cntb = cntc = 0;
		ans = 0;
		cin >> n;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&x[i][0],&x[i][1],&x[i][2]);
			if(x[i][0]>=x[i][1]&&x[i][0]>=x[i][2]){
				a[++cnta].id=i;	
				a[cnta].y = (x[i][0]-max(x[i][1],x[i][2]));
			}else if(x[i][2]>=x[i][1]&&x[i][2]>=x[i][0]){
				c[++cntc].id=i;
				c[cntc].y = (x[i][2]-max(x[i][0],x[i][1]));
			}else{
				b[++cntb].id=i;
				b[cntb].y = (x[i][1]-max(x[i][0],x[i][2]));
			}
		}
		if(cnta>n/2){
			sort(a+1,a+1+cnta,cmp);
			for(int i=1;i<=n/2;i++) ans+=x[a[i].id][0];
			for(int i=n/2+1;i<=cnta;i++)
				ans+=max(x[a[i].id][1],x[a[i].id][2]);
			for(int i=1;i<=cntb;i++) ans+=x[b[i].id][1];
			for(int i=1;i<=cntc;i++) ans+=x[c[i].id][2];
		}else if(cntb>n/2){
			sort(b+1,b+1+cntb,cmp);
			for(int i=1;i<=n/2;i++) ans+=x[b[i].id][1];
			for(int i=n/2+1;i<=cntb;i++)
				ans+=max(x[b[i].id][0],x[b[i].id][2]);
			for(int i=1;i<=cnta;i++) ans+=x[a[i].id][0];
			for(int i=1;i<=cntc;i++) ans+=x[c[i].id][2];
		}else if(cntc>n/2){
			sort(c+1,c+1+cntc,cmp);
			for(int i=1;i<=n/2;i++) ans+=x[c[i].id][2];
			for(int i=n/2+1;i<=cntc;i++)
				ans+=max(x[c[i].id][1],x[c[i].id][0]);
			for(int i=1;i<=cnta;i++) ans+=x[a[i].id][0];
			for(int i=1;i<=cntb;i++) ans+=x[b[i].id][1];
		}else{
			for(int i=1;i<=cnta;i++) ans+=x[a[i].id][0];
			for(int i=1;i<=cntb;i++) ans+=x[b[i].id][1];
			for(int i=1;i<=cntc;i++) ans+=x[c[i].id][2];
		}
		printf("%d\n",ans);
	}
	return 0;
} 

#include <bits/stdc++.h>
#define int long long
using namespace std;
const signed LEN=1e5+5;
bool used[LEN];
struct Node{
	int id,x;
} a[LEN],b[LEN],c[LEN];
bool cmp(Node u,Node v){
	if (u.x!=v.x)return u.x>v.x;
	return u.id<v.id;
}
int t,n,ad[LEN][5],bx[LEN],dp[LEN][5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n;
		int ans=0;
		bool flg1=true,flg2=true,flg3=true;
		for (int i=1;i<=n;i++){
			cin>>ad[i][1]>>ad[i][2]>>ad[i][3];
			if (ad[i][2]!=0 || ad[i][3]!=0)flg1=false;
			if (ad[i][1]!=0 || ad[i][3]!=0)flg2=false;
			if (ad[i][2]!=0 || ad[i][1]!=0)flg3=false;
		}
		if (flg1){
			for (int i=1;i<=n;i++)bx[i]=ad[i][1];
			sort(bx+1,bx+1+n);
			for (int i=n;i>=n/2+1;i--)ans+=bx[i];
			cout<<ans<<'\n';
			continue;
		}
		if (flg2){
			for (int i=1;i<=n;i++)bx[i]=ad[i][2];
			sort(bx+1,bx+1+n);
			for (int i=n;i>=n/2+1;i--)ans+=bx[i];
			cout<<ans<<'\n';
			continue;
		}
		if (flg3){
			for (int i=1;i<=n;i++)bx[i]=ad[i][3];
			sort(bx+1,bx+1+n);
			for (int i=n;i>=n/2+1;i--)ans+=bx[i];
			cout<<ans<<'\n';
			continue;
		}
		for (int i=1;i<=n;i++){
			a[i].x=ad[i][1],b[i].x=ad[i][2],c[i].x=ad[i][3];
			a[i].id=i,b[i].id=i,c[i].id=i;
			used[i]=false;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		int ad=1,bd=1,cd=1;
		while (ad<=n/2 && bd<=n/2 && cd<=n/2){
			int maxx=max(max(a[ad].x,b[bd].x),c[cd].x);
			if (a[ad].x==maxx && ad<=n/2 && !used[a[ad].id])ans+=a[ad].x,used[a[ad].id]=true;
			if (b[bd].x==maxx && bd<=n/2 && !used[b[bd].id])ans+=b[bd].x,used[b[bd].id]=true;
			if (c[cd].x==maxx && cd<=n/2 && !used[c[cd].id])ans+=c[cd].x,used[c[cd].id]=true;
			if (used[a[ad].id] && ad<=n/2)ad++;
			if (used[b[bd].id] && bd<=n/2)bd++;
			if (used[c[cd].id] && cd<=n/2)cd++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0


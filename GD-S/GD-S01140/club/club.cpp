#include <bits/stdc++.h>
using namespace std;

int t,n,ans,top,cnt[5],a[110000][5],mx[110000],s[5][110000],q[110000];

bool cmp(int x,int y){ return x>y; }

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	while(t--){
		ans=top=0;
		
		cnt[1]=cnt[2]=cnt[3]=0;
		
		cin >> n;
		
		for (int i=1; i<=n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			mx[i]=1;
			if(a[i][2]>a[i][mx[i]])  mx[i]=2;
			if(a[i][3]>a[i][mx[i]])  mx[i]=3;
			ans+=a[i][mx[i]];
		}
		
		for (int i=1; i<=n; i++){
			s[mx[i]][++cnt[mx[i]]]=i;
		}
		
		if(cnt[1]>n/2){
			for (int i=1; i<=cnt[1]; i++){
				q[++top]=max(a[s[1][i]][2],a[s[1][i]][3])-a[s[1][i]][1];
			}
			
			sort(q+1,q+top+1,cmp);
			
			for (int i=1; i<=cnt[1]-n/2; i++)  ans+=q[i];
		}
		else if(cnt[2]>n/2){
			for (int i=1; i<=cnt[2]; i++){
				q[++top]=max(a[s[2][i]][1],a[s[2][i]][3])-a[s[2][i]][2];
			}
			
			sort(q+1,q+top+1,cmp);
			
			for (int i=1; i<=cnt[2]-n/2; i++)  ans+=q[i];
		}
		else if(cnt[3]>n/2){
			for (int i=1; i<=cnt[3]; i++){
				q[++top]=max(a[s[3][i]][1],a[s[3][i]][2])-a[s[3][i]][3];
			}
			
			sort(q+1,q+top+1,cmp);
			
			for (int i=1; i<=cnt[3]-n/2; i++)  ans+=q[i];
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}

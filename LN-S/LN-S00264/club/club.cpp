#include<bits/stdc++.h>
#define int long long
using namespace std;


int T,n;
int a[200005][3],b[200005];


struct Person{
	int fav,dis;
	bool operator < (const Person &x) const{
		return dis < x.dis;
	}
};

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> T;
	while(T--){
		vector<Person>m[3];
		int ans=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			int p=-1;
			Person tmp={0,INT_MAX};
			for(int j=0;j<=2;j++){
				if(p!=-1) tmp.dis=min(tmp.dis,abs(a[i][p]-a[i][j]));
				if(p==-1||a[i][j]>a[i][p]){
					p=j;
					tmp.fav=a[i][j];
				}
			}
			ans+=tmp.fav;
			m[p].push_back(tmp);
		}
		int p=-1;
		for(int i=0;i<=2;i++) if(m[i].size()>n/2) p=i;
		if(p==-1) cout << ans << endl;
		else{
			sort(m[p].begin(),m[p].end());
			for(int i=0;i<m[p].size()-n/2;i++){
				ans-=m[p][i].dis;
			}
			cout << ans << endl;
		}
	}
	return 0;
}

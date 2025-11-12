#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
struct student{
	int C[4][3];//从大到小存//告诉我每个数据对应哪个社团 
}S[N];
bool cmp(student A,student B){
	return (A.C[1][1]-A.C[2][1])>(B.C[1][1]-B.C[2][1]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++){
			pair<int,int> x[4];
			cin >> x[1].first >> x[2].first >> x[3].first;
			x[1].second=1,x[2].second=2,x[3].second=3;
			sort(x+1,x+4);
			for(int j=3;j>=1;j--){
				S[i].C[4-j][1]=x[j].first;
				S[i].C[4-j][2]=x[j].second;
			}
			//cout << S[i].C[1][1] << ' ' << S[i].C[2][1] << ' ' << S[i].C[3][1] << endl;

		}
		sort(S+1,S+n+1,cmp);
		long long cnt[4]={0,0,0,0},ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[S[i].C[1][2]]<(n/2)){
				cnt[S[i].C[1][2]]++;
				ans+=S[i].C[1][1];
			}else{
				cnt[S[i].C[2][2]]++;
				ans+=S[i].C[2][1];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

#include <bits/stdc++.h> 
using namespace std;

const int N = 2e5 + 10;
int t, n, arr[N][3], cnt[3];
long long ans;
struct st{
	int idx, ma, sma;
}stt[N];

bool cmp1(const pair<int, int> &a, const pair<int, int> &b){
	return a.first > b.first;
}

bool cmp2(const st &a, const st &b){
	if((arr[a.idx][a.ma] - arr[a.idx][a.sma]) == (arr[b.idx][b.ma] - arr[b.idx][b.sma])) return arr[a.idx][a.ma] > arr[b.idx][b.ma];
	return (arr[a.idx][a.ma] - arr[a.idx][a.sma]) > (arr[b.idx][b.ma] - arr[b.idx][b.sma]);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		memset(cnt, 0, sizeof(cnt));
		memset(stt, 0, sizeof(stt));
		memset(arr, 0, sizeof(arr));
		ans = 0;
		cin >> n;
		//for(int i = 0;i < n;i++) cout << stt[i].idx << " " << stt[i].ma << " " << stt[i].sma << endl;
		for(int i = 0;i < n;i++){
			scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
			vector<pair<int, int>> at(3);
			at[0].first = arr[i][0];at[0].second = 0;
			at[1].first = arr[i][1];at[1].second = 1;
			at[2].first = arr[i][2];at[2].second = 2;
			sort(at.begin(), at.end(), cmp1);
			stt[i].idx = i;
			stt[i].ma = at[0].second;
			stt[i].sma = at[1].second;
		}
		sort(stt, stt + n, cmp2);
		for(int i = 0;i < n;i++){
			if(cnt[stt[i].ma] < n / 2){
				ans += arr[stt[i].idx][stt[i].ma];
				cnt[stt[i].ma]++;
			}
			else{
				ans += arr[stt[i].idx][stt[i].sma];
				cnt[stt[i].sma]++;
			}
		}
		//for(int i = 0;i < n;i++) cout << stt[i].idx << " " << stt[i].ma << " " << stt[i].sma << endl;
		printf("%lld\n", ans);
	}
	
	return 0;
}

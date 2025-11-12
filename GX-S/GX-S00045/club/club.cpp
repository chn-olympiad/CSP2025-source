#include <fstream>
#include <vector>

using namespace std;

ifstream cin("club.in");
ofstream cout("club.ans");
vector<vector<short>> manyi;
vector<int> at;
int bumen[4];
int n;
int ans = -114514;
void fill(vector<int> &vec , int x){
	for(int &e : vec){
		e = x;
	}
}
void dfs(int chosen , int to , int tot , int person){
	++bumen[to];
	at[chosen] = to;
	if(!person){
		ans = max(ans , tot);
		return;
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!at[i]){
			for(int j = 1 ; j <= 3 ; ++j){
				if(bumen[j] < n/2){
					dfs(i , j , tot+manyi[i][j] , person-1);
					--bumen[j];
					at[i] = 0;
				}
			}
		}
	}
}

void Main(){
	ans = 0;
	cin >> n;
	at.resize(n+1);
	manyi.resize(n+1 , vector<short>(4));
	for(int i = 1 ; i <= n ; ++i){
		cin >> manyi[i][1] >> manyi[i][2] >> manyi[i][3];
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= 3 ; ++j){
			bumen[1] = bumen[2] = bumen[3] = 0;
			fill(at , 0);
			dfs(i , j , manyi[i][j] , n-1);
		}
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--)Main();
	return 0;
}

//WTX
#include <iostream>
#include <vector>
using namespace std;
int n,k;
int cnt;
int a[500005];
vector<pair<int,int>> v;
bool vis[500005];
void n3s(){
	//30PTS
    for (int i = 1;i<=n;i++){
        for (int j = i;j<=n;j++){
            int sm = 0;
            for (int k1 = i;k1<=j;k1++) sm^=a[k1];
            if (sm==k){
                if (i==j){
					cnt++;
					vis[i]=1;
				}
				else{
					v.push_back({i,j});
				}
				break;
            }
        }
    }
	for (auto k : v){
		int l = k.first,r = k.second;
		bool fl = 0;
		for (int i = l;i<=r;i++){
			if (vis[i]){
				fl=1;
				break;
			}
		}
		if (fl) continue;
		cnt++;
		for (int i = l;i<=r;i++){
			vis[i]=1;
		}
	}
    cout << cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1;i<=n;i++){
	cin >> a[i];
    }
	n3s();
}
/****
aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
jiu jiu hai zi ba
*****/
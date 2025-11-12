#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n,m,a[2 * N],ansi,ansj,s;
bool cmp(int x,int y){
	return x > y;
}
int main(){
//    freopen("seat3.in","r",stdin);
//    freopen("number.txt","w",stdout);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i ++){
    	cin >> a[i];
	}
	s = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	ansi = 0,ansj = 0;
	for(int i = 1;i <= m;i ++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j ++){
				if(a[(i - 1) * n + j] == s){
					ansi = i;
					ansj = j;
					break;
				}
			}
		}else{
			for(int j = n;j >= 1;j --){
				if(a[(i - 1) * n + (n - j + 1)] == s){
					ansi = i;
					ansj = j;
					break;
				}
			}
		}
		if(ansi > 0 && ansj > 0){
			break;
		}
	}
	cout << ansi << ' ' << ansj;
    return 0;
}

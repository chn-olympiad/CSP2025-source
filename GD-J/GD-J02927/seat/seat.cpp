#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n,m;
int roc = 0;
int a[N];
bool cmp(int a,int b){
	return a > b; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	roc = n * m;
	for (int i = 1;i <= roc;i++){
		cin >> a[i];
	}
	int R = a[1];
	sort(a + 1,a + roc + 1,cmp);
	for (int i = 1;i <= roc;i++){
		if (a[i] == R){
			int ein = i % n,zwei = i / n;
			if (ein == 0){
				zwei--;
				ein = n;
			}
			if (zwei % 2 == 0){
				cout << zwei + 1 << " " << ein;
				return 0; 
			}
			else{
				cout << zwei + 1 << " " << n - ein + 1;
				return 0;
			}
		}
	}
	
	return 0;
}
/*Notes:
I AK CSP,RP+=1e9
*/

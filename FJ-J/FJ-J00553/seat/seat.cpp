#include<bits/stdc++.h>
using namespace std;
int n,m;
int sl1[1005];
int sl2[105][105];
bool cmp(int x,int y){
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<=n*m; i++) {
		cin>>sl1[i];
	}
	int temp1 = sl1[1];
	int lis;
	sort(sl1+1,sl1+n*m+1,cmp);
	int now = 0;
	bool flag = 0;
	for(int i = 1; i<=n; i++) {
		if(i%2 == 1) {
			for(int j = 1; j<=m; j++) {
				now++;
				if(sl1[now] == temp1){
					cout<<i<<" "<<j;
					flag = 1;
					break;
				}
			}
			
		} else {
			for(int j = m; j>=1; j--) {
				now++;
				if(sl1[now] == temp1) {
					cout<<i<<" "<<j;
					flag = 1;
					break;
				}
			}

		}
		if(flag) {
			break;
		}
	}
	return 0;
}


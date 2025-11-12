#include<bits/stdc++.h>
using namespace std;
int n,m,x = 1,y = 1;
int A[1010];
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)cin >> A[i];
	int t = A[1];
	sort(A + 1,A + 1 + n * m);
	for(int i = n * m;i >= 1;i--){
		if(A[i] == t){
			cout << y << " " << x;
			return 0;
		}
		if((x == n) && (y % 2 != 0))y++;
		else if((x == 1) && (y % 2 == 0))y++;
		else if((x < n) && (y % 2 != 0))x++;
		else if((x > 1) && (y % 2 == 0))x--;
	}
	
	return 0;
}

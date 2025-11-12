#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans,mn,mx,md= 0;
	cin >> n >> m;
	int s[n*m-1];
	int seat[n][m];
	cin >> ans;
	s[0] = ans;
	for(int i = 1;i<n*m;i++){
		cin >> ans;
		s[i] = ans;
		for(int j = 0;j<=i;j++){
			mx = max(s[j],s[j-1]);
			mn = min(s[j],s[j-1]);
			s[j-1] = mx;
			s[j] = mn;
			mx = max(s[j],s[j+1]);
			mn = min(s[j],s[j+1]);
			s[j] = mx;
			s[j+1] = mn;
		}
	}
	for(int z = 1;z<=n;z++){
		for(int y = 1;y<=m;y++){
			if(z%2 == 1&&s[(z-1)*m+y] == ans){
				cout << z << " " << y;
				return 0;
			}
			else if(z%2 == 0&&s[(z-1)*m+y] == ans){
				cout << z << " " << m-y+1;
				return 0;
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

int n,m,a[150],s[15][15],r;

bool CMP(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 0;i < n * m;++i){
		cin >> a[i];
	}
	r = a[0];
	sort(a,a + n * m,CMP);
	
	int i = 0,j = 0,cnt = 0;
	s[i][j] = a[cnt++];
	while(cnt < n * m){
		while(i < n - 1){
			s[++i][j] = a[cnt++];
			if(s[i][j] == r){
				cout << j + 1 << ' ' << i + 1 << endl;
				return 0;
			}
		}
		s[i][++j] = a[cnt++];
		if(s[i][j] == r){
			cout << j + 1 << ' ' << i + 1 << endl;
			break;
		}
		while(i > 0){
			s[--i][j] = a[cnt++];
			if(s[i + 1][j] == r){
				cout << j + 1 << ' ' << i + 1 << endl;
				return 0;
			}
		}
		s[i][++j] = a[cnt++];
		if(s[i][j] == r){
			cout << j + 1 << ' ' << i + 1 << endl;
			break;
		}
	}
	return 0;
}

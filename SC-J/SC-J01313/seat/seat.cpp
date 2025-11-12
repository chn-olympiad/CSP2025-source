#include<bits/stdc++.h>

using namespace std;

const int N = 110;

int n,m,mn,h=1,l=1,sitt;
int a[N],mapp[70][70];

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	mn = n * m;
	for(int i = 1;i <= mn;i++){
		cin >> a[i];
		if(i == 1) sitt = a[i];
	}
	sort(a+1,a+mn+1,cmp);
//	for(int i = 1;i <= mn;i++) cout << a[i] << ' ';
	for(int i = 1;i <= mn;i++){
		mapp[l][h] = a[i];
		if(h == n && l % 2 == 1){
			l++;
			continue;
		}else if(h == 1 && l % 2 == 0){
			l++;
			continue;
		}
		
		if(l % 2 == 1){
			h++;
			continue;
		}else if(l % 2 == 0){
			h--;
			continue;
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			if(mapp[i][j] == sitt)
				cout << i << ' ' << j;
//			cout << mapp[i][j] << ' ';
		}
//		cout << endl;
	}
	return 0;
}
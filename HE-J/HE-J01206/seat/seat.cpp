#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int n,m;
int a[110];
bool cmp(int s1,int s2){
	return s1>s2;
}
int score;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	rep(i,1,n*m){
		cin >> a[i];
	}
	score = a[1];
	int idx;
	sort(a+1,a+1+n*m,cmp);
	int ii = 1,jj = 0;
	rep(i,1,n*m) {
		if (ii % 2 == 1) jj++;
		else jj--;
		if (jj > m || jj < 1){
			ii++;
			if (ii % 2 == 0) jj = m;
			else jj = 1;
		}
		if (score == a[i]){
			idx = i;
			break;
		}
	}
	printf("%d %d",ii,jj);
	return 0;
}


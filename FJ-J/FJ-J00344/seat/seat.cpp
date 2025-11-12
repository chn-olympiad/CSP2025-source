#include <bits/stdc++.h>
using namespace std;
int s[10000][10000],n,m,c,r,a[1000000],ans,k,t;

int ps(){
	int j=1;
	while(j<=m){
		if(j%2==0){
			for(int x=m;x>=1;x--){
				s[x][j] = a[t];
				t--;
				if(s[x][j]==ans){
					c = j;
					r = x;
					cout << c << " " << r << endl;
				}
			}
			j++;
		}
		for(int i=1;i<=n;i++){
			s[i][j] = a[t];
			t--;
			if(s[i][j]==ans){
				c = j;
				r = i;
				cout << c << " " << r << endl;
			}
		}
		j++;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	k = n*m;
	t = k;
	for(int i=1;i<=k;i++){
		cin >> a[i];
	}
	ans = a[1];
	sort(a,a+k+1);
	ps();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
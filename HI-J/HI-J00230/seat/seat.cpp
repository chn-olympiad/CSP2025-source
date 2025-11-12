#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int s[11][11], a[101];

bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i=0; i<n*m; i++){
		scanf("%d", &a[i]);
	}
	int x = a[0];
	sort(a, a+m*n, cmp);
	int t=0;
	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
        	s[i][j] = a[t];
        	t++;
		}
	}
	for(int i=1; i<n; i+=2){
		sort(s[i], s[i]+m);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(s[i][j]==x) cout << i+1 << ' ' << j+1;
		}
	}
	
	
	return 0;
}


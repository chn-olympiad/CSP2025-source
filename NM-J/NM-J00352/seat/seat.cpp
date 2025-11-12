#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    long long w[10005];
    for(int i=0;i<n*m;i++){
    	cin >> w[i];
	}
    long long x=w[0],y = 0;
    sort(w,w+n*m);
    for(long long i=n*m;i>0;i--){
		if(x == w[i]){
			y = i;
		}
    }
    for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;j++){
			if(j == y){
				cout << i << " " << j;
				y = 0;
				break;
			}
    	}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}

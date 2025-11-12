#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int cmp(int a,int b){
	return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n*m;i++){
        cin >> a[i];
    }
    int point = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i] == point) cout << 1  << " " << i;
	}
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n;
int a[50000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int maxn=-1;
	maxn=max(maxn,a[1]);
	maxn=max(maxn,a[2]);
	maxn=max(maxn,a[3]);
	if(maxn==a[1]){
        if((a[2]+a[3])*2>a[1]){
            cout << 1;
        }
	}
	if(maxn==a[2]){
        if((a[1]+a[3])*2>a[2]){
            cout << 1;
        }
	}
	if(maxn==a[3]){
        if((a[2]+a[1])*2>a[3]){
            cout << 1;
        }
	}
	return 0;
}

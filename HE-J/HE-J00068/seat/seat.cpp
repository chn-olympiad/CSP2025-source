#include<bits/stdc++.h>
using namespace std;

int a[110];
int maxn;
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n*m; i++) {
		cin>>a[i];
        if(maxn < a[i]){
        	maxn = a[i];
		}
	}
	if(a[0] = maxn){
		cout<<1<<" "<<1;
	}
	return 0;
} 

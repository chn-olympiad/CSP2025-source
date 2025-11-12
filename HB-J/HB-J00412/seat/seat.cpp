#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[11451411];//,d[105][105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	
	int s = a[1];
	int j;
	int k = n*m;
	sort(a+1,a+1+k,cmp);
	for(int i = 1;i<=n;i++){
		int o=0;
		int d[1145][1145];
		if(i%2==1){
			j = 1;
		}else j = m;
		if(j == 1){
			for(int z = 1;z<=m;z++){
				o++;
				d[i][z] = a[o];
				if(a[o] == s){
					cout<<i<<" "<<z;
					return 0;
				}
			}
		}else {
			for(int z = m;z>=1;z--){
				o++;
				d[i][z] = a[o];
				if(a[o] == s){
					cout<<i<<" "<<z;
					return 0;
				}
			}
		}
	}
	return 0;
}

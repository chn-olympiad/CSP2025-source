#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1010;// xian zhi zhi you 10 
int n,m,a[N];
bool cmp(int X,int Y){
	return X>Y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	
	int tmp=a[1];
	
	sort(a+1,a+1+n*m,cmp);
	
	int cnt=0;
	
	for(int i=1;i<=n;i++){// hang
		if(i%2==0){
			for(int j=m;j>=1;j--){
				cnt++;				
				if(a[cnt]==tmp){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(i%2==1){
			for(int j=1;j<=m;j++){
				cnt++;				
				if(a[cnt]==tmp){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	return 0;
}


//检查！样例可靠性低 

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[110];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c=1;
    cin>>a[1];
    c=a[1];
    for(int i=2;i<=n*m;i++) cin>>a[i];
    sort(a+1,a+n*m+1,greater<int>());
    int nx=1,ny=1,k=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
        	if(a[++k]==c){
        		cout<<nx<<" "<<ny;
			}
			ny++;
		}
    	ny-=n;
    	nx++;	
	}
	return 0;
}
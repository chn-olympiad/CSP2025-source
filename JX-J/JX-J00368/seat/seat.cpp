#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[10005];
int a[105][105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;++i) cin>>f[i];
	int ps = f[0];
    sort(f,f+n*m,cmp);
	for(int i=0,k=0;i<n;++i){
		if(i%2==0){
			for(int j=0;j<m;++j,++k){
				a[i][j] = f[k];
				if(a[i][j]==ps){
                    cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}else{
            for(int j=m-1;j>=0;--j,++k){
				a[i][j] = f[k];
				if(a[i][j]==ps){
                    cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}

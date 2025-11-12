#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	int xb;
	for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            xb=i;
            break;
        }
	}
	int lie=(xb+n-1)/n;
	int l=(lie-1)*n+1,r=lie*n;
	int hang;
	if(lie%2==1){
        hang=xb-l+1;
	}else{
	    hang=r-xb+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}

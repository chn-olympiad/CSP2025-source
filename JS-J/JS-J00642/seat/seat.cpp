#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,vh[15][15];
struct nod{
	int s,id;
} a[110];
bool cmp(nod q,nod p){
	return q.s>p.s;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	/*for(int i=1;i<=n*m;i++){
		cout<<a[i].id<<" "<<a[i].s<<endl;
	}*/
	int x=1,y=1,f=0;
	vh[x][y]=a[1].id;
	for(int i=2;i<=n*m;i++){
		if(f==0){
			if(x==n){
				y++;
				f=1;
			} else {
				x++;
			}	
		} else {
			if(x==1){
				y++;
				f=0;
			} else {
				x--;
			}
		}
		vh[x][y]=a[i].id;
		//cout<<f<<" "<<x<<" "<<y<<" "<<a[i].id<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<vh[i][j]<<" ";
			if(vh[i][j]==1){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
		//cout<<endl;
	}
    return 0;
}

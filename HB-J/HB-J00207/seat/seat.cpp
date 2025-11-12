#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){return x>y;}
int n,m,a[105],mp[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=1,y=a[1],xx=0,yy=0;
	stable_sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				mp[i][j]=a[x];
				if(a[x]==y){
					xx=i,yy=j;
					break;
				}
				//cout<<i<<" "<<j<<" "<<a[x]<<endl;
				x++;
			}
		}else{
			for(int j=m;j>=1;j--){
				mp[i][j]=a[x];
				if(a[x]=y){
					xx=i,yy=j;
					break;
				}
				//cout<<i<<" "<<j<<" "<<a[x]<<endl;
				x++;
			}
		}
	}
	cout<<xx<<" "<<yy;
	return 0;
}

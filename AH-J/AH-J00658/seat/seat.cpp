#include<bits/stdc++.h>
using namespace std;
int cj[110];
int n,m;
int x,y;
int xr;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	xr=cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	bool flag=true;
	int cnt=1;
	int i=1,j=1;
	for(int xm=1;xm<=m*n;xm++){
		if(flag==true){
			while(i<=n){
				if(cj[cnt]==xr){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
				i++;
				cnt++;
			}
			i--;
			j++;
			flag=false;
		}
		if(flag==false){
			while(i>=1){
				if(cj[cnt]==xr){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
				i--;
				cnt++;
			}
			i++;
			j++;
			flag=true;
		}
	}
	return 0;
}

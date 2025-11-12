#include<bits/stdc++.h>
using namespace std;
int n,m,f,d[105],a[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>d[i];
	}
	f=d[1];
	sort(d+1,d+1+n*m,cmp);
	int h=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(d[h]==f){
					cout<<i<<" "<<j;
					return 0;
				}
				h++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(d[h]==f){
					cout<<i<<" "<<j;
					return 0;
				}
				h++;
			}
		}
	}
	return 0;
}

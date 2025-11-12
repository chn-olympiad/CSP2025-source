#include<bits/stdc++.h>
using namespace std;
int n,m,num=-1e9-7;
int sum;
int o=0;
int a[105];
int b[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	if(num==a[1]){
		cout<<1<<" "<<1;
		return 0;
	}
	int x=0;
	for(int i=1;i<=m;i++){
		if(o==0){
			for(int k=1;k<=n;k++){
				x++;
				b[k][i]=a[x];
				if(num==b[k][i]){
					cout<<i<<" "<<k;
					return 0;
				}
				o=2;
			}
		}
		if(o==2){
			o=1;
			continue;
		}
		if(o==1){
			for(int k=n;k>=1;k--){
				x++;
				b[k][i]=a[x];
				if(b[k][i]==num){
					cout<<i<<" "<<k;
					return 0;
				}
				o=0;
			}
		}
	}
	
}

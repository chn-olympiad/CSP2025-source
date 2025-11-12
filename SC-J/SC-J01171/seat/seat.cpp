#include <bits/stdc++.h>
using namespace std;
int a[110],b[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int h=n*m;
	for(int i=1;i<=h;i++) cin>>a[i];
	int f=a[1],num=1;
	sort(a+1,a+h+1,cmp);
	for(int i=1;i<=h;i++)
		if(a[i]==f)
			num=i;
	int w=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(w==num){
					cout<<i<<" "<<j;
					return 0;
				}
				w++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(w==num){
					cout<<i<<" "<<j;
					return 0;
				}
				w++;
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt;
int b[15][15];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	int num1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			num1=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[++cnt];
				if(cnt==num1){
					cout<<i<<" "<<j;
					return 0;
				}		
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[++cnt];
				if(cnt==num1){
					cout<<i<<" "<<j;
					return 0;
				}		
			}
		}
	}
	return 0;
}

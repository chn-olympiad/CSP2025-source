#include<bits/stdc++.h>
using namespace std;
int n,m,a[105]={0},s[15][15],cnt=1;
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
	int b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s[j][i]=a[cnt];
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				s[j][i]=a[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b==s[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

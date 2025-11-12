#include <bits/stdc++.h>
using namespace std;
int a[110];
int b[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	int k=s;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a,a+s);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[k--];
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[k--];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==x){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

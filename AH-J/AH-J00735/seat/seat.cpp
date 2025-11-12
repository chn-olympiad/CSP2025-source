#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],t,b[1010][1010],c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
		t=a[1];
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				c++;
				b[i][j]=a[c];
			}
			if(i%2==0){
				c++;
				b[i][n-j+1]=a[c];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==t){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
    return 0;
}
//#Shang4Shan3Ruo6Shui4

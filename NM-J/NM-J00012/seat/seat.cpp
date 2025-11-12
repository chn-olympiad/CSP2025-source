#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[1005];
int b[20][20];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int k=1;k<=n*m;k++){
		int j=(k-1)/m+1,i;
		if(j%2==1){
			i=(k-1)%n+1;
		}else{
			i=n-(k-1)%n;
		}
		b[i][j]=a[k];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(sum==b[i][j]){
				cout<<j<<" "<<i;
			}
		}
	}
    return 0;
}
/*
 * 约100+100+40+40=280吧
	最低……，不知道……
	燃尽了……
	qwq
	AK,IOI!!
	while(1) rp++;
*/

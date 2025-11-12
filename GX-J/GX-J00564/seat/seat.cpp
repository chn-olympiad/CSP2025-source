#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10][10],n,m,r,chenji[100],cntnmg=1;
bool cmp(int x,int y){
	if(x<y)return 0;
	return 1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> r;
	chenji[1]=r;
	for(int i=2;i<=(m*n);i++){
		cin >> chenji[i];
	}
	sort(chenji+1,chenji+(m*n),cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=chenji[cntnmg];
				if(chenji[cntnmg]==r){
					cout << i <<' '<< j;
					return 0;
				}
				cntnmg++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[i][j]=chenji[cntnmg];
				if(chenji[cntnmg]==r){
					cout << i <<' '<< j;
					return 0;
				}
				cntnmg++;
			}
		}
	}
	return 0;
}

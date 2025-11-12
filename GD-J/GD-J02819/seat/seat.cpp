#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct al{
	int id;
	int soc;
}a[1005],ac[15][15];
int n,m;
bool cmp(al a,al b){
	return a.soc>b.soc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i].soc;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	bool fl=true;
	int tot=1;
	for (int i=1;i<=m;i++){
		if (fl){
			for (int j=1;j<=n;j++){
				ac[j][i]=a[tot];
				tot++;
			}
		}
		else {
			for (int j=n;j>0;j--){
				ac[j][i]=a[tot];
				tot++;
			}
		}
		fl=1-fl;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (ac[i][j].id==1){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
2 2
98 99 100 97
2 2
99 100 97 98
*/

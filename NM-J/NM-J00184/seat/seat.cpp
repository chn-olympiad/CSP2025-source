#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[13][13];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int r=a[1][1],num=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r<a[i][j]){
				num++;
			}
		}
	}
	int lie=(num/m)+1;
	int hang;
	if(lie%2==0){
		hang=m-(num-((num/m)*m));
	}
	else if(lie%2==1){
		hang=(num-((num/m)*m))+1;
	}
	cout<<lie<<' '<<hang;
	return 0;
}

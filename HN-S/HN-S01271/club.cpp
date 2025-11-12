#include<bits/stdc++.h>
using namespace std;
int n,t,qaz;
int a[123456][9];
struct{
	int m,l,k,u;
}d[123456][9];
int main(){
	freopen("club.in",'r',stdin);
	freopen("club.out",'w',stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int o=1;o<=3;o++){
				cin>>a[j][o];
			}
		}
		for(int j=1;j<=n;j++){
			for(int p=1;p<=3;p++){
				d[j][p].m=max(d[j-1][1].m,d[j-1][2].m);
				d[j][p].m=max(d[j-1][3].m,d[j][p].m);
				if(d[j][p].m==d[j-1][1].m) d[j][p].l++;
				if(d[j][p].m==d[j-1][w].m) d[j][p].k++;
				d[j][p].m=d[j][p].m+a[j][p];
			}
		}
		qaz=max(d[n][1].m,d[n][2].m);
		qaz=max(d[n][3].m,qaz);
		cout<<qaz<<endl;
		qaz=0;
	}
	return 0;
}

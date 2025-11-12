#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],ma,mi,a1=0,a2=0,a3=0;
struct s{
	int m,p;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			ma=INT_MAX;
			mi=INT_MIN;
			for(int j=1;j<=3;j++){
				cin>>a[i][j].m;
				ma=max(ma,a[i][j].m);
				mi=min(mi,a[i][j].m);
			}
			for(int j=1;j<=3;j++){
				if(a[i][j].m==ma) a[i][j].p=1;
				else if(a[i][j].m==mi) a[i][j].p=3;
				else a[i][j].p=2;
			}
		}
		
	}
	return 0;
}

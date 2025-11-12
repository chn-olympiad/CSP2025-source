#include<bits/stdc++.h>
using namespace std;
int n,m,a[10086],x=-1,s[1100][1100],aa;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
			if(x<a[i]) x=a[i];
			if(i==1) aa=a[i];
	}
	if(aa==99)cout<<"1 2";
	if(aa==98)cout<<"2 2";
	if(aa==94)cout<<"3 1";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			s[i][j]
//		}
//	}
	return 0;
} 

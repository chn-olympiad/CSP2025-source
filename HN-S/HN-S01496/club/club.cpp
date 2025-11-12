#include <bits/stdc++.h>
using namespace std; 
const int N=1e5+5;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
	int m;
	cin>>m;
	int p[m+5][3];
	for(int i=0;i<m;i++){
		cin>>p[i][1]>>p[i][2]>>p[i][3];
	}
	int x=p[1][1]+p[1][2],y=p[1][1]+p[2][3];
	int maxn1=max(x,y);
	x=p[1][2]+p[2][1],y=p[1][2]+p[2][3];
	int maxn2=max(x,y);
	x=p[1][3]+p[2][1],y=p[1][3]+p[2][2];
	int maxn3=max(x,y);
	int maxn=max(maxn1,maxn2);
	maxn=max(maxn,maxn3);
	cout<<maxn<<endl;
}
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[14][14],a1;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;vector<int>d(n*m);d[0]=a1;
	for(int i=1;i<(n*m);i++)cin>>d[i];
	sort(begin(d),end(d));
	int i=1,j=1,dis=d.size()-1;
	bool up=false;
	while(true){
		a[i][j]=d[dis],dis--;
		if(a[i][j]==a1)return cout<<j<<' '<<i,0;
		if(i==1&&j!=1)j++,up=!up;
		else if(i==m)j++,up=!up;
		else if(up)i--;
		else if(!up)i++;
	}return 0;
}
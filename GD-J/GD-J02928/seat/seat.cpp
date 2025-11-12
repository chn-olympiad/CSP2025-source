#include<bits/stdc++.h>
using namespace std;
int mark[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>mark[i];
	R=mark[1];
	sort(mark+1,mark+n*m+1,greater<int>());
	for(int i=1;i<=m;i++)
		if(i%2){
			for(int j=1;j<=n;j++)
				if(R==mark[++cnt]){
					cout<<i<<' '<<j;
					return 0;
				}
		}
		else
			for(int j=n;j;j--)
				if(R==mark[++cnt]){
					cout<<i<<' '<<j;
					return 0;
				}
	return 0;
}


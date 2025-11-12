#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;
const int N=105;
int a[N][N],c[N*N],n,m,k=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>c[i];
	for(int i=2;i<=n*m;i++)
		if(c[i]>c[1]) k++;
	int x=1,y=1;
	for(int i=1;i<k;i++){
		if(x&1) y==n?x++:y++;
		else y==1?x++:y--;
	}
	cout<<x<<" "<<y<<"\n";
	return 0;
}


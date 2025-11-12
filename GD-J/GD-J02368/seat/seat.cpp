#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[1000],b[15][15],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int w=m*n;
	for(int i=1;i<=w;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+w+1);
	int k=w;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			//b[j][i]=a[k--];
			if(a[k--]==s)cout<<i<<' '<<j;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

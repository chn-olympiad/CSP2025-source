#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,x,y=0;
	int t;
	cin>>t;
	cin>>n;
	    for(int i=1;i<=n;i++){
		int j=1;
		int a[i][j];
		cin>>a[i][j] >>a[i][j+1] >>a[i][j+2];
		x=max(a[i][j],max(a[i][j+1],a[i][j+2]));
		y=y+x;
		}
	cout<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

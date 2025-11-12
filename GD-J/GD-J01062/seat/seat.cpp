#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int j=1;
	while(a[j]!=r) j++;
	int l=j%n==0?j/n:j/n+1,f=j%n==0?n:j%n,h=l%2==1?f:n-f+1;
	cout<<l<<" "<<h;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

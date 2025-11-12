#include<bits/stdc++.h>
using namespace std;
struct ren{
	int c,y;
};
bool yan(ren a,ren b){
	return a.c>b.c;
}
ren a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a[1].y=1;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].c;
	sort(a+1,a+n*m+1,yan);
	int t=1,y=0;
	for(int i=1;i<=m;i++){
		if(i%2==0)
			for(int j=n;j>0;j--){
				if(a[t].y){
					cout<<m<<" "<<n;
					y=1;
					break;
				}
				t++;
			}
		else
			for(int j=1;j<=n;j++){
				if(a[t].y){
					cout<<i<<" "<<j;
					y=1;
					break;
				}t++;
			}
		if(y)
			break;
	}
	return 0;
}
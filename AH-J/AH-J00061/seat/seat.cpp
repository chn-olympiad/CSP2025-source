#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,b,x=1,y=1,j;
	freopen("seat.in","r",stdin);
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	b=a[0];
	sort(a,a+n*m);
	j=n*m-1;
	freopen("seat.out","w",stdout);
	if(a[j]==b){
		cout<<x<<" "<<y;
		return 0;
	}
	while(x<=m){
		j--;
		if(x%2!=0)
			y++;
		else
			y--;
		if(a[j]==b){
			cout<<x<<" "<<y;
			break;
		}
		if(y==n||y==1){
			j--;
			x++;
			if(a[j]==b){
				cout<<x<<" "<<y;
				break;
			}
		}
	}
	return 0;
}

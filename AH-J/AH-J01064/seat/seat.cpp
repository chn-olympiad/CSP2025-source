#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1005],r;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
			cin>>a[i];
	}
	int w=a[1];
	sort(a+1,a+t+1);
	for(int i=t;i>=0;i--){
		if(a[i]==w){
			r=t-i+1;
			break;
		}
	}
	int x=r/n,y=r%n;
	if(y>0){
		x++;
	}
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
}

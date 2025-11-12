#include <bits/stdc++.h>
using namespace std;
int n,m,a[100007]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int p=a[1];
	sort(a+1,a+n*m+1);
	int c=1,r=0;
	for(int j=n*m;j>=1;j--){
		if(r==1&&c%2==0) c++;
		else if(r==n&&c%2==1) c++;
		else if(c%2==1) r++;
		else if(c%2==0) r--;
		if(a[j]==p){
		cout<<c<<" "<<r;
		return 0;
	    }
	}
	
}

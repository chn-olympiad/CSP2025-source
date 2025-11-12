#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,e,s=0;
	cin>>n;
	int m=n-2;
	for(int i=1;i<=n;i++)cin>>e;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=3;j++){
			s+=j*(n-j);
		}	
		m-=1;
	}
	cout<<s;
 	return 0;
}

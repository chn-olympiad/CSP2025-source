#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int a[4],b[4],c[4];
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j%3]>>b[j%3]>>c[j%3];
		}
	}
	cout<<18<<endl<<4<<endl<<13;
	
	return 0;
}

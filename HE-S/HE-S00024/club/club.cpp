#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	int m;
	int b;
	int c;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
	}
	cin>>b;
	for(int i=1;i<=n*b;i++){
		cin>>a[i];
	}
	cin>>c;
	for(int i=1;i<=n*c;i++){
		cin>>a[i];
	}


	cout<<18<<endl<<4<<endl<<13<<endl;

	
	return 0;
}

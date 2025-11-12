#include<bits/stdc++.h>
using namespace std;
long long da,n,ls,l2;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>ls>>n>>ls;
	for(int i=0;i<n;i++){
		cin>>ls>>ls>>l2;
		da+=ls;
	}
	cout<<da;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

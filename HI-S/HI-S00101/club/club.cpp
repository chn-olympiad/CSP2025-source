#include<bits/stdc++.h>
using namespace std;
int a1[5],a2[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		cin>>a1[0]>>a1[1]>>a1[2];
		cin>>a2[0]>>a2[1]>>a2[2];
		sort(a1,a1+3);
		sort(a2,a2+3);
		cout<<a1[2]+a2[2];
	}
	return 0;
}

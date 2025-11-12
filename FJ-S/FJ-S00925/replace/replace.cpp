#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			cin>>a[i][j];
		}
	}
	return 0;
}

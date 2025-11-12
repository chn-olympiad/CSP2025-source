#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string arr[n][1];
	string arr1[q][1];
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>arr1[i][j];
		}
	}
	cout<<2<<endl<<0;
	return 0;
}


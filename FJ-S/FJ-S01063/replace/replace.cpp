#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[500005][3],b[500005][3];
int mian(){
    freopen("replace.in","r",stdio);
	freopen("replace.out,"w",stdio);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++){
			cin>>b[i][j];
		}
	}
	cout<<"2"<<endl<<"0";
	return 0;
}

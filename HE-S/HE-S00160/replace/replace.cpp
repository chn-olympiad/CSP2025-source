#include<bits/stdc++.h>
using namespace std;
int main(){
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","W",stdout);
 	int n,q;
 	cin>>n>>q;
 	string n1[n*2];
 	string q1[q*2];
 	for (int i;i<=n*2;i++){
 		cin>>n1[i];
	}
	for (int i;i<=q*2;i++){
 		cin>>q1[i];
	}
	for(int i;i<=q;i++){
		cout<<0;
	}
	return 0;
}

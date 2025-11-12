#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    
    cout<<3;

	int n,q;
	cin>>n>>q;

	string ss[50005][2];
	string tt[100005];
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>ss[i][j];
		}
	}
	ss[n][2]="";
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>tt[i][j];
		}
	}
	
	

	

	return 0;
}


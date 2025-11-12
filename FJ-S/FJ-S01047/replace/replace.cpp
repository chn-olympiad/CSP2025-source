#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string a[100001][2],b[100001][2];
	int n,q;
	
	cin >> n>>q;
	for(int i=1;i<=n;i++){
		cin >> a[i][0]>>a[i][1];
	}
	for(int i=1;i<=q;i++){
		
	}
	for(int i=1;i<=q;i++){
		cin >> b[i][0]>>b[i][1];
		if(b[i][0]!=b[i][1]){
			cout <<0<<endl;
		}
	}
	
	return 0;
}

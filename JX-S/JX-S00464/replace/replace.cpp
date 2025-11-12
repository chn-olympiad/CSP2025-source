#include<bits/stdc++.h>
using namespace std;
char a[5000010];
char b[5000010];
			string t;
			string ttt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n;
	cin>>n;
	int q;
	cin>>q;
	while(q--){
		cin>>a>>b;
			cin>>t>>ttt;
			if(t==ttt){
				cout<<0<<endl;
			}
		else{
			for(int i=0;i<n;i++){
				if(t[0]=='b'){
					cout<<0<<endl;
					break;
				}
			}
			cout<<1<<endl;
		}
	}
	return 0;
}

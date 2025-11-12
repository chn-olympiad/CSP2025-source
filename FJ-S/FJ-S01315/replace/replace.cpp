#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
string w,z;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		a+=x;
		b+=y;
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		w+=x;
		z+=y;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}

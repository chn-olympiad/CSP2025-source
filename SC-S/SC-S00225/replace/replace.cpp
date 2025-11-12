#include<bits/stdc++.h>
using namespace std;
const int N=3e4+100;
struct node {
	string a,b;
} t[N];
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>t[i].a>>t[i].b;
	for(int i=1; i<=m; i++) {
		int ans=0;
		string x,y,a,b;
		cin>>x>>y;
		string z=x;
		for(int j=1;j<=n;j++){
			string z=x;
			int pos=x.find(t[j].a);
			
//			cout<<pos<<" ";
			if(pos==-1) continue;
			int top=0;
			for(int p=pos;p<=pos+t[j].a.size()-1;p++){
				z[p]=t[j].b[top++];
			}
//			cout<<z<<" "<<y<<endl;
			if(z==y) ans++;
		}

		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
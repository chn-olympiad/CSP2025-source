#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("repalce.in","r",stdin);
	freopen("repalce.out","w",stdout);
	int n,q,d=0;
	cin>>n>>q;
	string s[n][2],t[q][2],g,h;
	for(int i=0;i<n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=0;i<n;i++)
		cin>>t[i][0]>>t[i][1];
	cout<<t[1][0];
	for(int j=0;j<q;j++){
		for(int i=0;i<n;i++){
			g=s[i][0];
			h=s[i][1];
			if(t[i][0]==g && t[i][1]==h)
				d++;
		}
	}
	cout<<d;
	return 0;
}

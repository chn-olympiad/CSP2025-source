#include<bits/stdc++.h>
using namespace std;
string s[200005],t[200005];
int n,q;
int tt[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    cin.ignore();
    for(int i=1;i<=n;i++)getline(cin,s[i]);
    for(int i=1;i<=q;i++)getline(cin,t[i]);
    for(int i=1;i<=n;i++){
		int a=0,b=0,c=0;
		for(int j=0;j<s[i].size();j++){
			//cout<<s[i][j];
			if(s[i][j]=='b'&&a==0)a=j+1;
			else if(s[i][j]=='b')b=j;
			if(s[i][j]==' ')c=j;
		}
		tt[abs(b-c-a)]++;
		//cout<<a<<b<<c<<endl;
	}
	for(int i=1;i<=q;i++){
		int a=0,b=0,c=0;
		for(int j=0;j<t[i].size();j++){
			//cout<<t[i][j];
			if(t[i][j]=='b'&&a==0)a=j+1;
			else if(t[i][j]=='b')b=j;
			if(t[i][j]==' ')c=j;
		}
		cout<<tt[abs(b-c-a)]<<endl;
	}
    return 0;
}

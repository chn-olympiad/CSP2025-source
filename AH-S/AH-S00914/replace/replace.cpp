#include<bits/stdc++.h>
using namespace std;
string y[200001];
map<string,string> y2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
   
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
		string s;
		cin>>y[i]>>s;
		y2[y[i]]=s;
	}
	string s,s2;
	int cnt=0;
	for(int i=1;i<=q;i++)
	{
		string o,p;
		cin>>o>>p;
		
		cout<<cnt<<endl;
	}
    
    return 0;
}

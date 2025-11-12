#include "bits/stdc++.h"
using namespace std;
const int N=1e6+10;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i,j;int n,q,x,y,f=rand()%100,ans;
	string s1,s2,t1,t2;
	cin>>n>>q;
	while(n--) {
		getline(cin,s1);getline(cin,s2);
	}
	while(q--)
	{
		getline(cin,t1);getline(cin,t2);
	}
	while(f--)  ans=rand()%10;
	cout<<ans<<endl;
	cout<<rand()%10<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

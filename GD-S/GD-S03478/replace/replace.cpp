#include<bits/stdc++.h>

using namespace std;

string getsub(string c,int s,int e)
{
	string o = "";
	for(int i = s;i <= e;i++)
	{
		o+=c[i];
	}
	return o;
}

int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	map<string,string> use;
	for(int i =1 ;i <= n;i++)
	{
		string a,b;
		cin>>a>>b;
		use[a] = b;
		use[b] = a;
	}
	for(int i = 1;i <= q;i++)
	{
		string x1,x2;
		cin>>x1>>x2;
		int all = 0;
		for(int j = 0;j < x1.size();j++)
		{
			for(int k = x1.size()-1 ; k > 0 ;k--)
			{
				if(j >= k)
				{
					break;
				}
				string sub = getsub(x1,j,k);
				string sub2 = getsub(x2,j,k);
				if(use.find(sub) != use.end() && use[sub] == sub2)
				{
					 all++;
				}
			}
		}
		cout<<all<<endl;
	}
	return 0;
} 

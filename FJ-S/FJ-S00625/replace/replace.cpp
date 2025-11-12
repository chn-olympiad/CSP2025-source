#include <iostream>
#include <cstring>
using namespace std;
int n,q,ans;
string db[200001][3],question[200001][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=0;i<n;i++)
	{
		cin >> db[i][0];
		cin >> db[i][1];
	}
	for(int j=0;j<q;j++)
	{
		cin >> question[j][0];
		cin >> question[j][1];
	}
	for(int k=0;k<q;k++)
	{
		for(int u=0;u<question[k][0].length();u++)
		{
			for(int v=1;v<=question[k][0].length()-u;v++)
			{
				for(int w=0;w<n;w++)
				{
					
					if(db[w][0] == question[k][0].substr(u,v))
					{
						string y = question[k][0].substr(0,u)+db[w][1]+question[k][0].substr(u+v,question[k][0].length()-u-v);				
						if(y == question[k][1]) ans++;
					}
				}
			}
		}
		cout << ans;
		ans = 0;
		if(k<q-1) cout << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n,q;

string a[200002];
unordered_map<string,string> dict;

int mibpo1[200002];
int mibpo2[200002];

//te bie xing zhi b

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> dict[a[i]];
		dict[dict[a[i]]] = a[i];
	}
	for(int j = 1;j <= n;j++)
	{
		int misize = a[j].size();
		int tm1 = -1;
		int tm2 = -1;
		for(int k = 0;k < misize;k++)
		{
			if(tm1 != - 1 && tm2 != -1){break;}
			if(a[j][k] == 'b'){tm1 = k;}
			else if(dict[a[j]][k] == 'b'){tm2 = k;}
		}
		mibpo1[j] = tm1;
		mibpo2[j] = tm2;
	}	
	while(q--)
	{
		//try special!
		string t1,t2;
		int b1 = -1,b2 = -1;
		cin >> t1 >> t2;
		int ans = 0;
		int size = t1.size();
		for(int i = 0;i < size;i++)
		{
			if(b1 != -1 && b2 != -1){break;}
			//cong zhe li kai shi ti huan
			if(t1[i] == 'b'){b1 = i;}
			if(t2[i] == 'b'){b2 = i;}
		}
		
		//chang shi yong mei ge zi fu chuan qu ti huan
		for(int j = 1;j <= n;j++)
		{
			
			//kai shi pi pei
			if(b1 >= mibpo1[j] && (b2 - b1) == (mibpo2[j]-mibpo1[j]))
			{
				ans++;
			}
			else if(b1 >= mibpo2[j] && (b2 - b1) == (mibpo1[j] - mibpo2[j]))
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    vector<int>a;
    int i;
    int q=s.size();
    for(i=0;i<q;i++)
    {
        if(s[i]=='9')	
		{
			a.push_back(9);
        }
        else if(s[i]=='8')
        {
			a.push_back(8);
        }
        else if(s[i]=='7')
        {
			a.push_back(7);
        }
        else if(s[i]=='6')
        {
			a.push_back(6);
        }
        else if(s[i]=='5')
        {
			a.push_back(5);
        }
        else if(s[i]=='4')
        {
			a.push_back(4);
        }
        else if(s[i]=='3')
        {
			a.push_back(3);
        }
        else if(s[i]=='2')
        {
			a.push_back(2);
        }
        else if(s[i]=='1')
        {
			a.push_back(1);
        }
        else if(s[i]=='0')
        {
			a.push_back(0);
        }
       
	}
    sort(a.begin(),a.end());
    int z=a.size()-1;
    for(i=z;i>=0;i--)
    {
	cout<<a[i];
    }
    return 0;
}

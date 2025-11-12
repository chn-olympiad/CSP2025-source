#include<bits/stdc++.h>
using namespace std;
string s[100005][3];
string t[100005][3];
bool find0(string s/*主串*/,int start,string t/*模式串*/)
{
	// cout<<"debugger\n";
	// cout<<s<<" "<<start<<"  "<<t<<endl;
	if(start+t.size()-1>s.size()){return false;}
	for(int i=0;i<t.size();i++)
	{
		if(s[i+start]!=t[i]){return false;}
	}
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);

	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];

	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int cnt=0;
		for(int i=1;i<=n;i++)//所有二元组
		{

			for(int j=0;j<t1.size();j++)//所有起始位置
			{
				if(find0(t1,j,s[i][1])){
					// cout<<233<<endl;	
					string tmp=t1;//替换逻辑
					for(int o=j;o<=j+s[i][2].size()-1;o++)
					{
						tmp[o]=s[i][2][o-j];
					}	
					// cout<<t1<<" "<<t2<<" "<<j<<" "<<s[i][1]<<" "<<tmp<<endl;
					if(tmp==t2)
					{
						cnt++;
						break;

					}			

				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
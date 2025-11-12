#include<iostream>
#include<string>
using namespace std;

int main() {
    string an;
	string s1,s2;
	string key,key1;
	freopen("replace.in","r",stdin);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		string a,b;
		cin>>a>>b;
		an=an+a+b;
	}
	for(int i=0; i<q; i++) {
		string s;
		cin>>s1>>s2;
		s=s+s1+s2;
		for(int i=0; i<s.size(); i++) {
			if(s[i]!=s[s1.size()+1]) {
				key+=s[i];
				key1+=s[s.size()+1];
			}
		}
		key+=key1;
		string w;
		for(int j=0;j<=key.size();j++)
		{
			for(int k=0;k<=key.size();k++)
			{
				if(an[j]==key[k])
				{
					
					w+=an[j];
					
				}
			}
		}
		int maxi=0;
		int cnt=0;
		int ans=0;
		for(int j=0;j<=key.size();j++)
		{
			for(int k=0;k<=key.size();k++)
			{
				if(w[j]==an[k])
				{
					cnt++;
					maxi=cnt;
					j++;
				}
				else
				{
					cnt=0;
					if(maxi==w.size())
					ans++;
				}
			}
		}
		freopen("replace.out","w",stdout);
		cout<<ans;
		return 0;
	}
}

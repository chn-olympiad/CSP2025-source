#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N], s2[N];
string t1, t2;
string h="", m="";
string x="", y="";
int ans;
int n, q;
map<string, bool>mp;
void find1(string s)
{
	for(int i=1; i<=n; i++)
		if(s==s1[i] && mp[s]==0){
			if(t2==x+s2[i]+y)
				ans++;
			mp[s]=1;
		}
	if(s.size()<=1) return;
	x+=s[0],
	h="";
	for(int i=1; i<s.size(); i++)
		h+=s[i];
	find1(h);
}
void find2(string s)
{
	for(int i=1; i<=n; i++)
		if(s==s1[i] && mp[s]==0){
			if(t2==x+s2[i]+y)
				ans++;
			mp[s]=1;
		}
	if(s.size()<=1) return;
	y+=s[s.size()-1],
	h="";
	for(int i=1; i<s.size(); i++)
		h+=s[i];
	find1(h);
	find2(h);
}
void find3(string s)
{
	for(int i=1; i<=n; i++)
		if(s==s1[i] && mp[s]==0){
			if(t2==x+s2[i]+y)
				ans++;
			mp[s]=1;
		}
	if(s.size()<=2) return;
	y+=s[s.size()-1],
	x+=s[0];
	h="";
	for(int i=1; i<s.size()-1; i++)
		h+=s[i];
	find1(h);
	find2(h);
	find3(h);
}
void find4(string s){
	for(int i=1; i<=n; i++)
		if(s==s1[i] && mp[s]==0){
			if(t2==x+s2[i]+y)
				ans++;
			mp[s]=1;
		}
	if(s.size()<=1) return;
	x+=s[0],
	h="";
	for(int i=1; i<s.size(); i++)
		h+=s[i];
	find2(h);
	find3(h);
}
void find5(string s)
{
	for(int i=1; i<=n; i++)
		if(s==s1[i] && mp[s]==0){
			if(t2==x+s2[i]+y)
				ans++; 
			mp[s]=1;
		}
	if(s.size()<=1) return;
	y+=s[s.size()-1],
	h="";
	for(int i=1; i<s.size(); i++)
		h+=s[i];
	find3(h);
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>s1[i]>>s2[i];
	for(int i=1; i<=q; i++)
	{
		cin>>t1>>t2;
		ans=0;
		find1(t1);
		x="", y="";
		find2(t1);
		x="", y="";
		find3(t1);
		x="", y="";
		find4(t1);
		x="", y="";
		find5(t1);
		cout<<ans<<endl;
	}
	return 0;
}

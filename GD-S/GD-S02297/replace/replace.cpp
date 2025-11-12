#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::string;

int n,q;
string str1[200005],str2[200005];

inline bool find(string s1,string s2,string s3,string s4){	//在s1中将s2替换为s3能否得到s4 
	int res = 0;
	for(int i = 0;i <= int(s1.length()) - int(s2.length());i += 1)
	{
		bool flag = true;
		for(int j = 0;j < int(s2.length());j += 1)
		{
			if(s1[i + j] != s2[j])
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			string s = s1;
			for(int j = 0;j < int(s2.length());j += 1)
			{
				s[i + j] = s3[j];
			}
			if(s == s4)
			{
				res += 1;
			}
		}
	}
	return res;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i += 1)
	{
		cin>>str1[i]>>str2[i];
	}
	while(q--)
	{
		long long ans = 0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i = 1;i <= n;i += 1)
		{
			ans += find(t1,str1[i],str2[i],t2);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

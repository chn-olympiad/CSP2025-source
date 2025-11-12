 #include <bits/stdc++.h> 
 using namespace std;
 int main()
 {
 	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x[10]={0};
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')x[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(x[i])
		{
			x[i]--;
			cout<<i;
		}
	}
 	return 0;
 }

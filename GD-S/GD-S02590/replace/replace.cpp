#include<bits/stdc++.h>
using namespace std;

long long n,q;
long long Start,End;

long long tmp;
long long ans;

bool flag;

struct edge{
	string s1,s2;
	long long ABS;
};

edge str[200005];

string s1,s2;
string s;

bool cmp(edge a,edge b)
{
	return a.ABS < b.ABS;
}

void check(long long Start,long long End,string a,string b)
{
	for(long long i = Start; i <= End; i++)
	{
		for(long long j = 0; j <= (long long)a.size() - (long long)str[i].s1.size(); j++)
		{
			if(str[i].s1[0] == a[j])
			{
				s = "";
				s += a.substr(0,j) + str[i].s2 + a.substr(j + str[i].s1.size(),a.size() - j - str[i].s1.size());
				
				if(s == b) ++ans;
			}
		}
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	
	for(long long i = 1; i <= n; i++)
	{
		cin >> str[i].s1 >> str[i].s2;
		str[i].ABS = str[i].s1.size() - str[i].s2.size();
	}
	
	sort(str + 1,str + 1 + n,cmp);
	
	for(long long i = 1; i <= q; i++)
	{
		ans = 0;
		cin >> s1 >> s2;
		
		tmp = s2.size() - s1.size();
		
		Start = 0,End = 1;
		flag = false;
		while(str[End].ABS <= tmp && End <= n) 
		{
			if(Start == 0 && str[End].ABS == tmp) 
			{
				Start = End;
				flag = true;
			}
			++End;
		}
		--End;	
		
		if(flag == false) 
		{
			cout << 0 << endl;
			continue;
		}
		
		check(Start,End,s1,s2);
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

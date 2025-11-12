#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m;
int id;
int ans;
string s[N][3];
string s1,s2;
bool b;

bool aaa(string s1,string s2,string s3,string s4,string ss1,string ss2)
{
	if(s1.size()!=s2.size()) return 0;
	string s5,s6,s7,s8,s9,s10,s11;
	b=0;
	id=0;
	int k1=s1.find(s3),k2=s2.find(s4);
	if(k1==-1) return 0;
	if(k1!=k2) return 0;
	if(s5!=s6||s7!=s8) return 0;
	if(ss1.find(s1)==ss2.find(s2)) return 1;
	else return 0;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(m--)
	{
		ans=0;
		string s3,s4;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			printf("0\n");
			continue;
		}
		int l=s1.size();
		for(int i=0;i<l;i++) if(s1[i]!=s2[i])
		{
			s3+=s1[i];
			s4+=s2[i];
		}
		for(int i=1;i<=n;i++) if(aaa(s[i][1],s[i][2],s3,s4,s1,s2)) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
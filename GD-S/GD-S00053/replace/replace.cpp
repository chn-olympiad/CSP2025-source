#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 10 ;
string s[N][2] ;
bool check(string s , int j , string t)
{
	for(int i = 0 ; i < (int)t.size() ; i++)
		if(s[i + j] != t[i]) return 0 ;
	return 1 ;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n , q ;
	scanf("%d%d",&n,&q) ;
	scanf("%*c") ;
	for(int i = 1 ; i <= n ; i++)
		cin>>s[i][0]>>s[i][1] ;
	while(q--)
	{
		string t1 , t2 ;
		cin>>t1>>t2 ;
		int ans = 0 ;
		for(int i = 1 ; i <= n ; i++)
			for(int j = 0 ; j < (int)t1.size() - (int)s[i][0].size() + 1 ; j++)
				if(check(t1,j,s[i][0]))
				{
					string t = t1 ;
					for(int k = 0 ; k < (int)s[i][0].size() ; k++)
						t[k + j] = s[i][1][k] ;
					if(t == t2) ans++ ;
				}
		printf("%d\n",ans) ;
	}
	return 0 ;
}

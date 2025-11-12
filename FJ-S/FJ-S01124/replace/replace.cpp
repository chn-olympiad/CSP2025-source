#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
string s1[N],s2[N];
//void kmp_init()
//{
//	
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,m;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> s1[i] >> s2[i];
	}
//	if(q==1)
//	{
//		
//	}
	int l,r;
	while(q--)
	{
		string t1,t2;
		cin >> t1 >> t2;
		m=t1.length();
		int p=0;
		while(t1[p]==t2[p])
		{
//		cout << t1[p] << " " << t2[p] << endl;
			p++;
		}
//		cout << p << endl;
		l=p;
//		if(l==t1.length()+1) l=1,r=t1.length();
		while(p<=t1.length() && t1[p]!=t2[p]) 
		{
			p++;
		}
		r=p-1;
		ll ans=0,st=0;	
//		cout << l <<" " << r << endl;
		for(int i=1;i<=n;i++)
		{
			int j=0,k=0;
			while(j<m)
			{
				if(s1[i][k]==t1[j] && s2[i][k]==t2[j])
				{
//					cout << i<< " " << j << " " << k << " " << "1#" << endl;
					if(k==0) st=j;
					k++;
					if(k==s1[i].length())
					{
						k=0;
						if(st<=l && j>=r) ans++;	
					}	
					j++;				
				}
				else j++,k=0;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
//Ren5Jie4Di4Ling5%

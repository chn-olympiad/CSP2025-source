#include<bits/stdc++.h>
using namespace std;

int n,q,sum;
const int MAX = 1e7;
string s1,s2;

struct {
	string x;
	string y;
	int lenth = x.size();
}a1[MAX];
struct {
	string a ;
	string b ;
	int lenth1;
	int lenth2;
}a2[MAX];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1; i <= n; i++) 
	{
		cin>>a1[i].x;
		cin>>a1[i].y;
		a1[i].lenth=a1[i].x.size();
	}
	for(int i = q; i >= 1; i--) 
	{
		cin>>a2[i].a;
		cin>>a2[i].b;
		a2[i].lenth1=a2[i].a.size();
		a2[i].lenth2=a2[i].b.size();
	}
	while(q)
	{
		if(a2[q].lenth1 != a2[q].lenth2) 
		{
			cout<<"0"<<endl;
			continue;
		}
		for(int i = 1; i <= n;i++)
		{
			int s=0;
			int m=0;
			for(int k = 0; k <a2[i].lenth1;k++)
			{
				if(a2[q].a[k] == a1[i].x[m]) {
					m++;
					s = k;
				}else{
					m = 0;
				}
				if(m == a1[i].lenth) break;
			}
			m = 0;
			if(s)for(int k = s;k <= a1[i].lenth;k++){
				a2[q].a[k] = a1[i].y[m];
				m++;
			}
			if(a2[q].a == a2[q].b) sum++;
			m = 0;
			for(int k = s;k <= a1[i].lenth;k++){
				a2[q].a[k] = a1[i].x[m];
				m++;
			}
		}
//------------------------------------------------------------------------
		cout<<sum<<endl;
		q--;
		sum = 0;
	}
	return 0;
}

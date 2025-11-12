//cx我爱你！！！ 
#include<bits/stdc++.h>
using namespace std;
string st;
int a[1010000],w;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	int l=st.size();
	for(int i=0;i<l;i++)
		if(st[i]>='0'&&st[i]<='9')
		{
			w++;
			a[w]=st[i]-'0';
		}
	sort(a+1,a+1+w);
	for(int i=w;i>=1;i--) cout<<a[i];
	return 0;
}
/*
太好了，这个可恶的十月终于过去了！o(*￣▽￣*)ブ 
真的有人不讨厌十月的吗('_'*)
每天的好心情都被这个月夺去了(T_T)
*/ 

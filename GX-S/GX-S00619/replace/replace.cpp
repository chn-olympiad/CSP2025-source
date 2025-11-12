#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int n,q,ans=0;
int* a[100010],b[100010];
string as1[100010],as2[100010],s1,s2,t;
void getNext(int[] q,string s)
{
	int ptr=0,ptr=0;
	q[0]=0;
	while(i<t.length())
	{
		if(s[i]==s[ptr])
		{
			q[i]=q[i-1]+1;
			ptr++;
			i++;
		}
		else {
			if(ptr!=0)
			ptr=q[ptr];
			else i++
		}
	}
}
void search(string t,string s)
{
	int ptr=0;
	for(int i=0;i<s.length();i++)
	{
		
	}	
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		cin>>t;
		as1[i]=t;
		a[i]=malloc(t.length());
		getNext(a[i],t);
		cin>>t;
		bs[i]=t;
		b[i]=malloc(t.length());
		getNext(b[i],t);
	}
	for(int i=0;i<q;i++)
	{
		cin>>s1>>s2;
		cout<<ans<<'\n';
	}
	return 0;
}

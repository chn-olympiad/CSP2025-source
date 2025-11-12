#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],b[500005],lb,fb,cnt;

/*
	T1 100,T2 100,T3 20,T4 0.That's all.
	There is some time(ten minutes) for me to write something.
	My English is not so good,so maybe there are some mistakes in the article.
	So,it's time to say goodbye to OI.This is my last time to join the CSP,and I will join the Chemistry Olympic Class next year.
	Many problem appeared in my way,but I went through until now.I love OI,however,I have to give up you because of my choice.
	I thank everyone who helped me.
	I thank my teacher ZJW and FWR,they taught me this knowledge so that I can sit there and write the article.
	I thank my parents,they encouraged me when I was disappointed and overtaken.I can't stand stress in such a long time without your words.
	I thank my friends ZJL and my classmates(many). They helped me a lot in this way.
	At last,I thank Farmer John,Bessie,Little Z,R,X,A(or other letters) and so on.You appeared in a lot of problems and I will remember you forever.
	The end,good wishes.
	rp++
*/

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1];
		if(a[i]==1)
		{
			if(fb==0)	fb=i;
			b[i]++;
			lb=i;
		}
	}
	if(b[n]==n)
	{
		cout<<n/2;
		return 0;
	}
	if(k==0)
	{
		if(lb==n&&fb==1)	cout<<b[n]/2;
		if(lb!=n&&fb==1)	cout<<b[n]/2+1;
		if(lb==n&&fb!=1)	cout<<b[n]/2+1;
		if(lb!=n&&fb!=1)	cout<<b[n]/2+2;
		return 0;
	}
	if(k==1)
	{
		cout<<b[n];
		return 0;
	}
	cout<<0;
	
	return 0;
} 

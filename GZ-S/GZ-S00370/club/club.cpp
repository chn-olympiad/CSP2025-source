//GZ-S00370 罗若渊 遵义第四初级中学 
#include<bits/stdc++.h>
using namespace std;
long long ans;
struct qq
{
	int a,b,c,d,e;
	bool friend operator<(qq x,qq y)
	{
		return x.d<y.d;
	}
}s[100000];
void ww(int n,int r,int now,int m,int aa,int bb,int cc)
{
	if(n==now)
	{
		if(m>ans){
			ans=m;
		}
		return;
	}
	if(aa<r-1)ww(n,r,now+1,m+s[now].a,aa+1,bb,cc);
	if(bb<r-1)ww(n,r,now+1,m+s[now].b,aa,bb+1,cc);
	if(cc<r-1)ww(n,r,now+1,m+s[now].c,aa,bb,cc+1);
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		int x,aa=0,bb=0,cc=0,n;
		cin>>x;
		n=x/2+1;
		for(int i=0;i<x;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			//if(s[i].a>=s[i].b){if(s[i].a>=s[i].c){s[i].d=s[i].a;s[i].e=1;}else{s[i].d=s[i].c;s[i].e=3;}}
			//else{if(s[i].b>=s[i].c){s[i].d=s[i].b;s[i].e=2;}else{s[i].d=s[i].c;s[i].e=3;}}
		}
		ww(x,n,0,0,0,0,0);
		//sort(s,s+t);
		cout<<ans<<endl;
		ans=0;
	}
	
	
 	return 0;	
} 
/*
Ren5Jie4Di4Ling5%


3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0





*/

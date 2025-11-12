#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a2,b2,c2;
struct f
{
    int a,b,c,num,club;
}like[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>like[i].a>>like[i].b>>like[i].c;
			if(like[i].a>=like[i].b&&like[i].a>=like[i].c)
			{
				a2++;
				like[i].club=1;
			}
			if(like[i].b>like[i].a&&like[i].b>=like[i].c)
			{
				b2++;
				like[i].club=2;
			}
			if(like[i].c>like[i].b&&like[i].c>like[i].a)
			{
				c2++;
				like[i].club=3;
			}
		}
		if(a2>n/2)
        {

            for(int i=1;i<=a2-n/2;i++)
            {
                for(int j=2;j<=n-i+1;j++)
                {
                    if(like[j].a-like[j].b>like[j-1].a-like[j-1].b&&like[j].a-like[j].b>like[j].a-like[j].c&&like[j-1].a-like[j-1].b>like[j-1].a-like[j-1].c)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                    if(like[j].a-like[j].c>like[j-1].a-like[j-1].c&&like[j].a-like[j].b<like[j].a-like[j].c&&like[j-1].a-like[j-1].b<like[j-1].a-like[j-1].c)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                    if(like[j].a-like[j].b>like[j-1].a-like[j-1].c&&like[j].a-like[j].b>like[j].a-like[j].c&&like[j-1].a-like[j-1].b<like[j-1].a-like[j-1].c)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                    if(like[j].a-like[j].c>like[j-1].a-like[j-1].b&&like[j].a-like[j].b<like[j].a-like[j].c&&like[j-1].a-like[j-1].b>like[j-1].a-like[j-1].c)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                }

            }
            for(int i=a2;i>n/2;i--)
            {
                if(like[i].a-like[i].b>like[i].a-like[i].c)
                {
                    like[i].club=2;
                }
                else
                {
                    like[i].club=3;
                }
            }
        }
        if(b2>n/2)
        {

            for(int i=1;i<=b2-n/2;i++)
            {
                for(int j=2;j<=n-i+1;j++)
                {
                    if(like[j].b-like[j].a>like[j-1].b-like[j-1].a&&like[j].b-like[j].a>like[j].b-like[j].c&&like[j-1].b-like[j-1].a>like[j-1].b-like[j-1].c)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                    if(like[j].b-like[j].c>like[j-1].b-like[j-1].c&&like[j].b-like[j].a<like[j].b-like[j].c&&like[j-1].b-like[j-1].a<like[j-1].b-like[j-1].c)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                    if(like[j].b-like[j].a>like[j-1].b-like[j-1].c&&like[j].b-like[j].a>like[j].b-like[j].c&&like[j-1].b-like[j-1].a<like[j-1].b-like[j-1].c)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                    if(like[j].b-like[j].c>like[j-1].b-like[j-1].a&&like[j].b-like[j].a<like[j].b-like[j].c&&like[j-1].b-like[j-1].a>like[j-1].b-like[j-1].c)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                }

            }
            for(int i=b2;i>n/2;i--)
            {
                if(like[i].b-like[i].a>like[i].b-like[i].c)
                {
                    like[i].club=1;
                }
                else
                {
                    like[i].club=3;
                }
            }
        }
        if(c2>n/2)
        {

            for(int i=1;i<=c2-n/2;i++)
            {
                for(int j=2;j<=n-i+1;j++)
                {
                    if(like[j].c-like[j].b>like[j-1].c-like[j-1].b&&like[j].c-like[j].b>like[j].c-like[j].a&&like[j-1].c-like[j-1].b>like[j-1].c-like[j-1].a)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                    if(like[j].c-like[j].a>like[j-1].c-like[j-1].a&&like[j].c-like[j].b<like[j].c-like[j].a&&like[j-1].c-like[j-1].b<like[j-1].c-like[j-1].a)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                    if(like[j].c-like[j].b>like[j-1].c-like[j-1].a&&like[j].c-like[j].b>like[j].c-like[j].a&&like[j-1].c-like[j-1].b<like[j-1].c-like[j-1].a)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                    if(like[j].c-like[j].a>like[j-1].c-like[j-1].b&&like[j].c-like[j].b<like[j].c-like[j].a&&like[j-1].c-like[j-1].b>like[j-1].c-like[j-1].a)
                    {
                        swap(like[j].a,like[j-1].a);
                        swap(like[j].b,like[j-1].b);
                        swap(like[j].c,like[j-1].c);
                        swap(like[j].num,like[j-1].num);
                        swap(like[j].club,like[j-1].club);
                    }
                }

            }
            for(int i=c2;i>n/2;i--)
            {
                if(like[i].c-like[i].b>like[i].c-like[i].a)
                {
                    like[i].club=2;
                }
                else
                {
                    like[i].club=1;
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(like[i].club==1)
                sum+=like[i].a;
            if(like[i].club==2)
                sum+=like[i].b;
            if(like[i].club==3)
                sum+=like[i].c;
        }
        cout<<sum<<endl;
	}
	return 0;
}

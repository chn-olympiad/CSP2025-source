#include<bits/stdc++.h>
using namespace std;

//  I love zll;

int n,m;
int score[105];
int r;
int nown=0,nowm=1;
int cdt=0;

int main()
{
 	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>score[i];
	}
	r=score[1];
	sort(score+1,score+1+n*m);
    for(int i=n*m;score[i]!=r;i--)
    {
        if(cdt==0 && nown!=n)
        {
            nown++;
        }
        else if(cdt==0 && nown==n)
        {
            cdt=1;
            nowm++;
        }
        else if(cdt==1 && nown!=1)
        {
            nown--;
        }
        else if(cdt==1 && nown==1)
        {
            cdt=0;
            nowm++;
        }
    }
    if(cdt==0 && nown!=n)
    {
        nown++;
    }
    else if(cdt==0 && nown==n)
    {
        cdt=1;
        nowm++;
    }
    else if(cdt==1 && nown!=1)
    {
        nown--;
    }
	else if(cdt==1 && nown==1)
    {
        cdt=0;
        nowm++;
    }
    cout<<nowm<<" "<<nown;
}

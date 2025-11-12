#include<bits/stdc++.h>
using namespace std;
int t;
int n[6];
int satis1[100005];
int satis2[100005];
int satis3[100005];
int chazhi12[100005];
int chazhi13[100005];
int chazhi23[100005];
int numb[5];
long long ans[6];
int min(int a,int b)
{
	if(a>b)
	{
		return b;
	}
	return a;
}
int cmp(int a,int b)
{
	return a<b;
}
int cmpmax(int a,int b,int c)
{
    if(a>=b&&a>=c)
    {
        return a;
    }
    else{	
		if(b>=a&&b>=c)
		{
			return b;
		}
		else{
			if(c>=a&&c>=b)
			{
				return c;
			}
		}
	}
    return 1;
}
int cmpsec(int a,int b,int c)
{
    if(a>=b)
    {
        if(b>=c)
        {
            return b;
        }
        if(b<c&&c<=a)
        {
            return c;
        }
        if(b<c&&c>a)
        {
            return a;
        }
    }
    else{
        if(b<=c)
        {
            return b;
        }
        if(b>c&&c<=a)
        {
            return a;
        }
        if(b>c&&c>a)
        {
            return c;
        }
    }
    return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i];
        for(int j=1;j<=n[i];j++)
        {
            scanf("%d%d%d",&satis1[j],&satis2[j],&satis3[j]);
            chazhi12[j]=max(satis1[j],satis2[j])-min(satis1[j],satis2[j]);
            chazhi23[j]=max(satis2[j],satis3[j])-min(satis2[j],satis3[j]);
            chazhi13[j]=max(satis3[j],satis1[j])-min(satis3[j],satis1[j]);
		}
        sort(chazhi12+1,chazhi12+n[i]+1,cmp);
        sort(chazhi13+1,chazhi13+n[i]+1,cmp);
        sort(chazhi23+1,chazhi23+n[i]+1,cmp);
        int sum=0;
        for(int k=1;k<=n[i];k++)
        {
            sum+=cmpmax(satis1[k],satis2[k],satis3[k]);
            if(satis1[k]==satis2[k]&&satis1[k]==satis3[k])
            {
				if(min(min(numb[1],numb[2]),numb[3])==numb[1])
				{
					numb[1]++;
					continue;
				}
				else if(min(min(numb[1],numb[2]),numb[3])==numb[2])
				{
					numb[2]++;
					continue;
				}
				else if(min(min(numb[1],numb[2]),numb[3])==numb[3])
				{
					numb[3]++;
					continue;
				}
			}
			else if(satis1[k]==satis2[k]&&satis1[k]>satis3[k])
			{
				if(min(numb[1],numb[2])==numb[1])
				{
					numb[1]++;
					continue;
				}
				else if(min(numb[1],numb[2])==numb[2])
				{
					numb[2]++;
					continue;
				}
			}
			else if(satis1[k]==satis3[k]&&satis1[k]>satis2[k])
			{
				if(min(numb[1],numb[3])==numb[1])
				{
					numb[1]++;
					continue;
				}
				else if(min(numb[1],numb[3])==numb[3])
				{
					numb[3]++;
					continue;
				}
			}
			else if(satis3[k]==satis2[k]&&satis3[k]>satis1[k])
			{
				if(min(numb[2],numb[3])==numb[2])
				{
					numb[2]++;
					continue;
				}
				else if(min(numb[2],numb[3])==numb[3])
				{
					numb[3]++;
					continue;
				}
			}
            else if(cmpmax(satis1[k],satis2[k],satis3[k])==satis1[k])
            {
				numb[1]++;
				continue;
			}
			else if(cmpmax(satis1[k],satis2[k],satis3[k])==satis2[k])
			{
				numb[2]++;
				continue;
			}
			else if(cmpmax(satis1[k],satis2[k],satis3[k])==satis3[k])
			{
				numb[3]++;
				continue;
			}
        }
        int cnt12=1;
        int cnt13=1;
        int cnt23=1;
        if(cmpmax(numb[1],numb[2],numb[3])==numb[1])
		{
			while(numb[1]>n[i]/2)
			{
				sum-=min(chazhi12[cnt12],chazhi13[cnt13]);
				if(min(chazhi12[cnt12],chazhi13[cnt13])==chazhi12[cnt12])
				{
					cnt12++;
				}
				else{
					cnt13++;
				}
				numb[1]--;
			}
		}
		else if(cmpmax(numb[1],numb[2],numb[3])==numb[2])
		{
			while(numb[2]>n[i]/2)
			{
				sum-=min(chazhi12[cnt12],chazhi23[cnt13]);
				if(min(chazhi12[cnt12],chazhi23[cnt23])==chazhi12[cnt12])
				{
					cnt12++;
				}
				else{
					cnt23++;
				}
				numb[2]--;
			}
		}
		else if(cmpmax(numb[1],numb[2],numb[3])==numb[3])
		{
			while(numb[3]>n[i]/2)
			{
				sum-=min(chazhi13[cnt13],chazhi23[cnt23]);
				if(min(chazhi13[cnt13],chazhi23[cnt23])==chazhi13[cnt13])
				{
					cnt13++;
				}
				else{
					cnt23++;
				}
				numb[3]--;
			}
		}
		ans[i]=sum;
		int kk=0;
		for(int aa=1;aa<=n[i];aa++)
		{
			if(satis2[aa]!=0||satis3[aa]!=0)
			{
				kk=1;
			}
		}
		if(kk==0)
		{
			ans[i]=0;
			sort(satis1+1,satis1+n[i]+1,cmp);
			for(int ww=n[i];ww>n[i]/2;ww--)
			{
				ans[i]+=satis1[ww];
			}
		}
		sum=0;
		cnt12=1;
        cnt13=1;
        cnt23=1;
        for(int j=1;j<=n[i];j++)
        {
			satis1[j]=0;
			satis2[j]=0;
			satis3[j]=0;
			chazhi12[j]=0;
			chazhi13[j]=0;
			chazhi23[j]=0;
			numb[1]=0;
			numb[2]=0;
			numb[3]=0;
		}
    }
    for(int i=1;i<=t;i++)
    {
		cout<<ans[i]<<endl;
	}
    return 0;
}

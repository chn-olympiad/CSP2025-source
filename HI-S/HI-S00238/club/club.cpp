#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int numa,numb,numc;
int v[100010];
struct people{
	int a;
	int b;
	int c;
};
people mun[100010]; 
bool amp(people x,people y){
    if (x.a>y.a) return true;
    return false;
}
bool bmp(people x,people y){
    if (x.b>y.b) return true;
    return false;
}
bool cmp(people x,people y){
    if (x.c>y.c) return true;
    return false;
}
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
    cin>>t;
    for (int time=1;time<=t;time++)
    {
    	ans=0,numa=0,numb=0,numc=0;
		int maxa=0,maxb=0,maxc=0;
    	cin>>n;
   	    for (int i=1;i<=n;i++)
    	{
    		mun[i].a=0;
    		mun[i].b=0;
    		mun[i].c=0;
		}
    	for (int i=1;i<=n;i++)
    	{
    		cin>>mun[i].a>>mun[i].b>>mun[i].c;
    		maxb=max(maxb,mun[i].b);
    		maxc=max(maxc,mun[i].c);
		}
    	for (int i=1;i<=n;i++)
    	{
    		v[i]=0;
		}

		sort(mun+1,mun+n+1,amp);
		if (maxb==0&&maxc==0) 
		{
			int m=1,i=1;
	    	while(m<=n/2)
	    	{
	    		ans+=mun[i].a;
	    		m++;
	    		i++;
	    	}			
		    cout<<ans<<endl;
		    continue;
		}	
	//	if (n==2) cout<<max(mun[1].a+mun[2].b,mun[1].a+mun[2].c,mun[1].b+mun[2].a,mun[1].a+mun[2].b)	
		for (int i=1;i<=n;i++)
		{
			if (numa>=n/2) break;
			if (mun[i].a>=mun[i].b)
			{
				if (mun[i].a>=mun[i].c)
				{
					ans+=mun[i].a;
					numa++;
					v[i]=1;
				}
			}
		}
		sort(mun+1,mun+n+1,bmp);		
		for (int i=1;i<=n;i++)
		{
			if (numb>=n/2) break;
			if (mun[i].b>=mun[i].c)
			{
				if (v[i]==0)
				{
					ans+=mun[i].b;
					numb++;
					v[i]=1;
				}
			}
		}
		sort(mun+1,mun+n+1,cmp);		
		for (int i=1;i<=n;i++)
		{
			if (numc>=n/2) break;
			if (v[i]==0)
			{
				ans+=mun[i].c;
				numc++;
				v[i]=1;
			}
		}
    	cout<<ans;			
	}
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
struct node{
	int a1,a2,a3,w,cha;
}a[2000001];
bool cmp(node x,node y)
{
	return x.cha<y.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		long long n,ans=0,w1=0,w2=0,w3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
	    int maxx=max(max(a[i].a1,a[i].a2),a[i].a3);
	    if(a[i].a1==maxx){
	    a[i].w=1;
	    a[i].cha=a[i].a1-max(a[i].a2,a[i].a3);
	    w1++;
	}
	    else
	    if(a[i].a2==maxx){
	    a[i].w=2;
	    a[i].cha=a[i].a2-max(a[i].a1,a[i].a3);
	    w2++; 
	}
	    else{
	    a[i].w=3;
	    a[i].cha=a[i].a3-max(a[i].a2,a[i].a1);
	    w3++;
	}
	ans+=maxx;
	}
	sort(a+1,a+n+1,cmp);
		if(w1>n/2)
		{
			int m=w1-(n/2),sum=0;
			for(int i=1;i<=n;i++)
           {if(sum==m)
              break;
			if(a[i].w==1)
		     {
		     	sum++;
		     	ans-=a[i].cha;
			 }
		}
		}
		if(w2>n/2)
		{
		int m=w2-(n/2),sum=0;
			for(int i=1;i<=n;i++)
           {if(sum==m)
              break;
			if(a[i].w==2)
		     {
		     	sum++;
		     	ans-=a[i].cha;
			 }
		}
	}
		if(w3>n/2)
		{
			int m=w3-(n/2),sum=0;
			for(int i=1;i<=n;i++)
           {if(sum==m)
              break;
			if(a[i].w==3)
		     {
		     	sum++;
		     	ans-=a[i].cha;
			 }
		}
	}
	cout<<ans<<endl;
}
	return 0;
} 

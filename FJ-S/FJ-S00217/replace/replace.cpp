#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
long n,q;
string s1[MAXN],s2[MAXN],t1[MAXN],t2[MAXN];
string d1[MAXN],d2[MAXN],d3[MAXN],d4[MAXN];
void differ1(string a,string b,long h)
{
	string c='0'+a,d='0'+b;
	long pl=1,l1=1,l2=c.length()-1;
	long pr=c.length()-1,r1=1,r2=c.length()-1;
	
	while(c[l1]==d[l1]||c[l1-1]!=d[l1-1])
	{
		if(c[l1]==d[l1])
		{
			pl=l1;
			l1=(l1+l2)/2;
		}  
		else
		{
			l2=l1;
			l1=pl;
		}
	}
	l1--;
	
	while(c[r2]==d[r2]||c[r2+1]!=d[r2+1])
	{
		if(c[r2]==d[r2])
		{
			pr=r2;
			r2=(r1+r2)/2;
		}  
		else
		{
			r1=r2;
			r2=pr;
		}
	}
	r2--;
	
	for(long u=l1;u<=r2;u++)
	    d1[h]+=a[u],d2[h]+=b[u];
}
void differ2(string a,string b,long h)
{
	string c='0'+a,d='0'+b;
	long pl=1,l1=1,l2=c.length()-1;
	long pr=c.length()-1,r1=1,r2=c.length()-1;
	
	while(c[l1]==d[l1]||c[l1-1]!=d[l1-1])
	{
		if(c[l1]==d[l1])
		{
			pl=l1;
			l1=(l1+l2)/2;
		}  
		else
		{
			l2=l1;
			l1=pl;
		}
	}
	l1--;
	
	while(c[r2]==d[r2]||c[r2+1]!=d[r2+1])
	{
		if(c[r2]==d[r2])
		{
			pr=r2;
			r2=(r1+r2)/2;
		}  
		else
		{
			r1=r2;
			r2=pr;
		}
	}
	r2--;
	
	for(long u=l1;u<=r2;u++)
	    d3[h]+=a[u],d4[h]+=b[u];
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

    cin>>n>>q;
    for(long i=0;i<n;i++){
    	cin>>s1[i]>>s2[i];
    	differ1(s1[i],s2[i],i);
	}
    
    for(long i=0;i<q;i++){
    	cin>>t1[i]>>t2[i];
    	if(t1[i].length()!=t2[i].length()){
    		cout<<0<<endl;
    		continue;
		}
    	differ2(t1[i],t2[i],i);
    	long ans=0;
    	for(int j=0;j<n;j++){
    		if(d3[i]==d1[j]&&d4[i]==d2[j])
    		    ans++;
		}	
    	cout<<ans<<endl;
	}
	
	return 0;
}

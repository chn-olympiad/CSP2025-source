#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,m,kk; 
int  xo(int q,int qq){
	int p[30],pp[30],re=1,ww=1;
	for(int i=1;i<=q;i++){
		if(q>re)
		  {
		  	re=re*2;
		  	ww++;
		  }
		else break;
	}
	int w=ww;
	while(q!=0){
		if(q>=re){
		  q-=re;
		  re/=2;
		  p[ww]=1;
		  ww--;
		}
		else {
			re/=2;
			ww--;
		}
	}
	int ree=1,www=1;
	for(int i=1;i<=qq;i++){
		if(qq>ree)
		   {
		   	ree=ree*2;
		   	www++; 
		   }
		else break;
	}
	w=max(w,www); 
	while(qq!=0){
	    if(qq>=ree){
		  qq-=ree;
		  ree/=2;
		  pp[www]=1;
		  www--;
		}
		else {
			ree/=2;
			www--;
		}
	}
	int ann=0,uu=1;
	for(int i=1;i<=w;i++)
	{
		if(p[i]==pp[i])
		{
			
		}
		else 
		{
			if(i==1)ann+=1;
			else	
			{
				ann+=uu;
			}
		}
		uu*=2;
//		cout<<uu<<'\n';
	}
//	cout<<ann<<'\n';
    k=kk;
	return ann;
}
void dfs(int x)
{
	ans=max(ans,m);
	int q=a[x],de=0;//qÎªÒì»òºÍ;
	for(int i=x+1;i<=n;i++)
	{
		if(xo(q,a[i])!=k)
		{
			k=kk;
			q=xo(q,a[i]);
//			cout<<xo(q,a[i]);
			k=kk;
//			cout<<q;
		}
		else
		{
			de=1;
			m++;
			dfs(i+1);
			m--;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	kk=k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)ans++;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

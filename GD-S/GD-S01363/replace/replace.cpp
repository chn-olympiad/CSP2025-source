#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
	int i1=-1,i2=-1;
}ch[5000];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,q,ans=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
	cin>>ch[i].s1>>ch[i].s2;
	for(int j=0;j<ch[i].s1.size();j++) 
        if(ch[i].s1[j]=='b') ch[i].i1=i;
       for(int j=0;j<ch[i].s2.size();j++) 
        if(ch[i].s2[j]=='b') ch[i].i2=i;
	}  
    for(int i=1;i<=q;i++)
    {
      string t1,t2;int im1=-1,im2=-1;
      cin>>t1>>t2;
      for(int j=0;j<t1.size();j++) 
        if(t1[j]=='b') im1=i;
       for(int j=0;j<t2.size();j++) 
        if(t2[j]=='b') im2=i;
      if(im1==-1||im2==-1) cout<<0<<endl;
      else
      {
        for(int j=1;j<=n;j++)
        {
          if(ch[j].i1>im1||ch[j].i2>im2) continue;
          else
          	if(ch[j].i1-ch[j].i2==im1-im2) ans++;
		}
	  }
	  cout<<ans<<endl;
	}
	return 0;
 } 


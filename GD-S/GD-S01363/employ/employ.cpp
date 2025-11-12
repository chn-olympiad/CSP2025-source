#include<bits/stdc++.h>
using namespace std;
const int maxn=520;
int s[maxn],c[maxn],t1[maxn],t2[maxn];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m;long long ans=1;string s1;
    cin>>n>>m;
    cin>>s1;
    for(int i=1;i<=n;i++) cin>>c[i],ans*=c[i];
    for(int i=1;i<=n;i++) s[i]=s1[i]-'0';
    /*for(int i=1;i<=n;i++)
    {
    	bool f=0;
    	for(int j=1;j<=c[i];j++)
          if(t[c[j]]<c[j]) {
          ans*=(c[j]-t[c[j]]);f=1;t[c[j]]++;
		  //cout<<ans<<" ";	
		  }
        if(f) sum++;
	}*/
	//cout<<sum<<endl;
	cout<<ans;
	return 0;
 } 


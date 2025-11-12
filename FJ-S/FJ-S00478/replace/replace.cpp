#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10; 
typedef long long ll; 

string t1[N],t2[N],s1[N],s2[N]; 
int  main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ll n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>t1[i]>>t2[i];
	for(int i=1;i<=q;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)
	{
		ll ans=0;
		for(int j=1;j<=n;j++)
		{
			if( s1[i].find(t1[j])<s1[i].size() && s2[i].find(t2[j])<s2[i].size() )
			{
			 	string s11=s1[i].substr(0,s1[i].find( t1[j]) ),s12=s1[i].substr( s1[i].find( t1[j] )+t1[j].size()  ,N) ;
			 	string s21=s2[i].substr(0,s2[i].find( t2[j]) ),s22=s2[i].substr( s2[i].find( t2[j] )+t2[j].size()  ,N) ;
			 	//cout<<s11<<" "<<s12<<" "<<s21<<" "<<s22<<endl; 
				if( s1[i].find(t1[j]) == s2[i].find(t2[j]) &&s11==s21&&s12==s22 ) 
				{
					ans++; 
			 		//cout<<s1[i].find(t1[j])<<" "; 
			 	}
			 }
//			cout<<"#"; 
		 } 
		cout<<ans<<endl; 
	 } 
	return 0;
}

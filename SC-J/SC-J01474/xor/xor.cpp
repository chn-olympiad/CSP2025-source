#include<bits/stdc++.h>
#define ll long long
#define jmy jiangmuyang
using namespace std;
const int MAXN=5e5+5; 
ll a[MAXN];
ll jmysum[MAXN];
int jmyt[1048580];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll jmyn,jmyk;
	cin>>jmyn>>jmyk;
	for(int i=1;i<=jmyn;i++)
	{
		cin>>a[i];
		jmysum[i]=jmysum[i-1] ^ a[i]; 
	}
	int lastpp=0;
	jmyt[0]++;
	ll ans=0;
	for(int i=1;i<=jmyn;i++)
	{
		if(jmyt[jmysum[i] ^ jmyk]>0)
		{
			ans++;
			for(int j=lastpp;j<i;j++)
			{
				jmyt[jmysum[j]]=0;
			}
			lastpp=i;
			jmyt[0]=0;
		}
		jmyt[jmysum[i]]++;
	}
	cout<<ans;
	return 0;
}

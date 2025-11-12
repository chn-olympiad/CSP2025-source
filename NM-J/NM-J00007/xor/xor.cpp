#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	bool b=false;
	long long n,k,i,j,ok,p,l=0,r=0,ans;
	vector<pair<long long,long long> > v;
	cin>>n>>k;
	long long s[n];
	for(i=0;i<n;i++)
	{
	   	cin>>s[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ans=((s[l])^(s[r+1]));
	    	for(int ok=l;ok<r;ok++)
	    	{
	    		ans=(ans^(s[ok]));
			}
			if(ans==k)
			{
				b=false;
				for(int p=0;p<v.size();p++)
				{
					if((v[p].first==l) || (v[p].first==r) || (v[p].second==l) || (v[p].second==r))
					{
						b=false;
						break;
					}
				}
				if(b==true)
				{
					v.push_back({l,r});
				}
			}
			r++;
		}
		r=0;
		l++;
		cout<<endl;
	}
	cout<<v.size();
	fclose(stdin);
    fclose(stdout);
    return 0;
}

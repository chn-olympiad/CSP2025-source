#include<algorithm>
#include<iostream>
#include<string>

using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        for(int i=1;i<=n;i++)
        {
			cin>>s[i];
			
		}
		long long sum=1;
		for(int i=1;i<=n;i++)
		
		{
			sum*=1;
		sum%=998244353;
	}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
        return 0;
}

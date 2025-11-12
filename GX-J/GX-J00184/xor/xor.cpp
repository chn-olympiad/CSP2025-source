#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s[500010],ans,cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);}
	for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	int c=1,e=1;
	while(true){
		int flag=0;
		for(int i=c;i<=n;i++)
		{
			for(int j=e;j<=i;j++)
			{int x=s[i]^s[j-1];if(x==k){ans++;c=i+1;e=i+1;flag=1;break;}}
			if(flag==1)break;
		}
		if(flag==0||c>n||e>n)break;
	}
	cout<<ans;
	return 0;
}

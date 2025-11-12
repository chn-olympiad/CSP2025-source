#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=3;i<=n;++i)
	{
		for(int j=1;j<=n-i+1;++j)
		{
			int s=0,maxx=-100000;
			for(int k=j;k<=j+i-1;++k)
			{
				s+=a[k];
				maxx=max(maxx,a[k]);
			}
			if(s>maxx*2)
			{
				ans++;
				cout<<j<<' '<<i<<endl;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


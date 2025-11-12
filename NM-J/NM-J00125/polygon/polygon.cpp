#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans=0;
long long t[5005]={0}; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[3]<a[1]+a[2])cout<<1;
		else cout<<0;
		return 0;
	}
	int minn=-1;
	for(int qwe=3;qwe<=n;qwe++)
	{
		int minnn;
		for(int i=1;i<=qwe-2;i++){
			t[min(5001,a[i]+a[qwe-1])]++;
			t[min(5001,a[i]+a[qwe-1])]%=998244353;
			minn=max(minn,min(5001,a[i]+a[qwe-1]));
		}
	    for(int i=a[qwe]+1;i<=minn;i++)
	    {
	    	ans+=t[i];
	    	ans%=998244353;
		}
		minnn=minn;
	    for(int i=1;i<=minn;i++){
	        t[min(5001,i+a[qwe])]+=t[i];
	        t[min(5001,i+a[qwe])]%=998244353;
			minnn=max(minnn,min(5001,t[i] ? i+a[qwe]:i));
		}
		minn=minnn;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}

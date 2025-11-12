//GZ-S00448 ËçÑôÖÐÑ§ ½ð¿¡Î°
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring> 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	fro("club.in","r",stdin);
	fro("club.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		int a1[20005],a2[20005],a3[20005];
		int flag2=0,flag3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			if(a2[i]) flag2=1;
			if(a3[i]) flag3=1;
		} 
		if((flag2==0)&&(flag3==0)){
			sort(a1+1,a1+n+1);
			unsigned long long ans=0;
			for(int i=n;i>n/2;i--) ans+=a1[i];
			cout<<ans<<endl;
		}
		else if(n==2){
			int ans=0;
			ans=a1[1]+a2[2];
			ans=max(a1[1]+a3[2],ans);
			ans=max(a2[1]+a1[2],ans);
			ans=max(a2[1]+a3[2],ans);
			ans=max(a3[1]+a1[2],ans);
			ans=max(a3[1]+a2[2],ans);
			cout<<ans<<endl;
		}
	}
	return 0;
}

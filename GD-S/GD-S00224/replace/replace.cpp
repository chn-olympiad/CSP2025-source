#include<bits/stdc++.h>
using namespace std;int a1,b1,i,t,l,r,j;char a[5000001],b[5000001];
map<array<string,2>,int>p;
main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	scanf("%d%d",&a1,&b1);for(i=1;i<=a1;i++){
		scanf("%s %s",a+1,b+1);t=r=strlen(a+1);l=1;
		while(l<=t&&a[l]==b[l])l++;l--;
		while(r&&a[r]==b[r])r--;r++;
		string w,v;
		for(j=l+1;j<r;j++)w+=a[j],v+=b[j];
		p[{w,v}]++;
	}while(b1--){
		scanf("%s %s",a+1,b+1);t=r=strlen(a+1);l=1;
		while(l<=t&&a[l]==b[l])l++;l--;
		while(r&&a[r]==b[r])r--;r++;
		string w,v;for(j=l+1;j<r;j++)w+=a[j],v+=b[j];
		if(!p.count({w,v}))printf("0\n");else printf("%d\n",p[{w,v}]);
	}
}

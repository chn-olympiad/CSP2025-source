#include<bits/stdc++.h>
using namespace std;
int m,ans,a[5010],s[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",a+i);
	sort(a,a+m);
	for(int i=1;i<=m;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=3;i<=m;i++){
		for(int j=1;j<i-1;j++){
			if(s[i]-s[j-1]>a[i]*2){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}

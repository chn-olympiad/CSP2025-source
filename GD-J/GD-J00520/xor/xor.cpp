#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("xor4.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	bool flag=1;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++;
		else{
			if(i<n&&a[i+1]==a[i])ans++,i+=2;
		}		
	}
	printf("%d\n",ans);
	fclose(stdin);
//	fclose(stdout);
	return 0;
}

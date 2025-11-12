#include<bits/stdc++.h>
using namespace std;
int n;
int a[50006];
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int total=0;
		int maxn=0;
		for(int j=n;j>=i;j--){
			if(a[j]>maxn)maxn=a[j];
			total+=a[j];
		}
		if(total-maxn>maxn)ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

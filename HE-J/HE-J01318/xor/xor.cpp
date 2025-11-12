#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int l=1,r=1;
	while(r<=n){
		int s1=0;
		for(int i=l;i<=r;i++){
			s1=s1^a[i];
		}
		if(s1==k){
			ans++;
			r++;
			l=r;
		}else{
			r++;
		}
	}
	printf("%d",ans);
	return 0;
}

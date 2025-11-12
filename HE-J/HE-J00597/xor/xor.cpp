#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[500010],s[500010];
int lst[1<<22];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	for(int i=1;i<=1<<22;i++){
		lst[i]=-114514;
	}
	s[1]=a[1];lst[s[1]]=1;
	lst[0]=0;
	int x=(s[1]==k?1:-1),ans=(s[1]==k?1:0);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]^a[i];
		if(lst[k^s[i]]+1>x&&lst[k^s[i]]+1>=0){
			
			x=i;
			ans++;
		}
		lst[s[i]]=i;	
	}
	printf("%d",ans);
	return 0;
}

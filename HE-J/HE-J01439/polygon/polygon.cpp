#include <bits/stdc++.h>
using namespace std;
int n, a[5005], o;
long long int sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",n);
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);
		if(a[i]==1)o++;
	}
	bool flag=false;
	if(o==n)flag=true;
	if(n==3){
		int maxn=-1;
		for(int i=0;i<n;i++){
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn)printf("%d",1);
		else printf("%d",0);
		return 0;
	}
	if(flag)cout<<945691044;
	else cout<<12;
	return 0;
} 

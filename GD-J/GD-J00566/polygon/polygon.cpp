#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s,ma=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
		if(a[i]>ma){
			ma=a[i];
		}
	}
	if(s>2*ma) printf("%d",1);
	else printf("%d",0);
	return 0;
}

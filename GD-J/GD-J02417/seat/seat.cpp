#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[1000],b,c,d,e;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++) cin>>a[i],a[i]=-a[i];
	b=a[1];
	sort(a+1,a+1+s);
	for(int i=1;i<=s;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	if(c%m==0) d=c/m,e=m;
	else d=c/m+1,e=c%m;
	if(d%2==0) e=m-e+1;
	printf("%d %d",d,e);
	return 0;
}

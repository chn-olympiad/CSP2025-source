#include<bits/stdc++.h>
using namespace std;
int n,m,a[230],wz,b[230];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int s=n*m;
	for(int i=1;i<=s;i++)scanf("%d",&a[i]);
	int k=a[1];
	sort(a+1,a+s+1);
	for(int i=1;i<=s;i++)b[i]=a[s-i+1];
	for(int i=1;i<=s;i++)
		if(b[i]==k){
			wz=i;
			break;
		}
	int l=wz/m,r=wz%m;
	if(wz) {
		if(!l)printf("1 %d",r);
		else if(!r){
			if(!(l%2))printf("%d 1",l);
			else printf("%d %d",l,n);
		}
		else if(!(l%2))printf("%d %d",l+1,r);
		else printf("%d %d",l+1,n-r+1);
	}
}


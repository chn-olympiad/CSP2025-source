#include<bits/stdc++.h>
using namespace std;
int n,m,num,exam,k,a[105],h;
bool cmp(int u,int v){
	return u>v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		scanf("%d",&a[i]);
	}
	exam=a[1];
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(a[i]==exam){
			k=i;
			break;
		}
	}
	h=(k-1)/n+1;
	if(h&1) printf("%d %d",h,(k-1)%m+1);
	else printf("%d %d",h,m-((k-1)%m));
	return 0;
}

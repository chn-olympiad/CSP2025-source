#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int aa=a[1];
	sort(a+1,a+n*m+1,cmp);
	int ai=0;
	for(int i=1;i<=n*m;i++)
		if(a[i]==aa) ai=i;
	int cnt=0,cnt2=0;
	if(ai%n==0){
		cnt=ai/n;
		if(cnt%2==0)
			cnt2=1;
		else 
			cnt2=m;
		printf("%d %d\n",cnt,cnt2);
		return 0;
	}
	else{
		cnt=ai/n+1;
		if(cnt%2==0)
			cnt2=m-(ai/n)+1;
		else
			cnt2=ai%n;
		printf("%d %d\n",cnt,cnt2);
		return 0;
	}
	return 0;
}

#include<bits/stdc++.h>
#define N 105
using namespace std;
int n,m,siz;
pair<int,int>a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m),siz=n*m;
	for(int i=1;i<=siz;i++)
		scanf("%d",&a[i].first),
		a[i].second=i;
	sort(a+1,a+siz+1);
	for(int i=siz,x=1,y=1;i>=1;i--){
		if(a[i].second==1)
			return printf("%d %d",x,y),0;
		if(x&1)
			if(y<n) y++;
			else x++;
		else
			if(y>1) y--;
			else x++;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
pair<int,int> a[N];
bool cmp(pair<int,int> p,pair<int,int> q){
	return p.first>q.first;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		int s;
		scanf("%d",&s);
		a[i]=make_pair(s,i);
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].second==1){
			int x=(i-1)/n+1;
			int y;
			if(x%2==1) y=(i-1)%n+1;
			else y=n-(i-1)%n;
			printf("%d %d",x,y);
			return 0;
		} 
	}
	return 0;
}

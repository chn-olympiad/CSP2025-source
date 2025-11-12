#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,id;
}s[10001];
bool cmp(stu x,stu y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i].a);
		s[i].id=i;
	}
	sort(s+1,s+n*m+1,cmp);
	int al;
	for(int i=1;i<=n*m;i++){
		if(s[i].id==1){
			al=i;break;
		}
	}
	int x=(al-1)/n+1,y=(al-1)%n;
	if(x%2==1)y++;else
	y=n-y;
	cout<<x<<" "<<y;
	return 0;
}

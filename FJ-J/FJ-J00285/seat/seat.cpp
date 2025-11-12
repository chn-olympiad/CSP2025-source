#include<bits/stdc++.h>
using namespace std;
int b[1086],m,n,cnt=1,r,xx,yy;
bool cmp(int xxx,int yyy){
	return xxx>yyy;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n; 
	for(int i=1;i<=m*n;i++){
			cin>>b[cnt];
			cnt++;
	}
	r=b[1];
	sort(b+1,b+cnt,cmp);
	for(int i=1;i<cnt;i++){
		if(b[i]==r)
			r=i;
	}
	xx=r/n+1;
	if (r<=n)
		xx=1;
	if(xx%2==1)
		if(r%n==0) yy=n;	
		else yy=r%n;
	else 
		if(r%n==0) yy=1;
		else yy=n-r%n+1;
	cout<<xx<<" "<<yy;
	return 0;
}

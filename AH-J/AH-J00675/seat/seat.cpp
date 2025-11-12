#include <bits/stdc++.h>
using namespace std;
struct stu{
	int x,y;
}a[105];
bool cmp(int aa,int bb){
	return aa>bb;
}
int n,m,i=1,j=1,k,b=1,c[105],p;
bool f=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	while(b<=k){
		if(f==0){
			a[b].x=i,a[b].y=j;
			if(i==n) j++,i--,f=1;
			i++;
		}
		else{
			a[b].x=i,a[b].y=j;
			if(i==1) j++,i++,f=0;
			i--;
		}
		b++;
	}
	for(int q=1;q<=k;q++) cin>>c[q];
	p=c[1];
	sort(c+1,c+k+1,cmp);
	for(int q=1;q<=k;q++){
		if(c[q]==p){
			cout<<a[q].y<<' '<<a[q].x;
			return 0;
		}
	}
	return 0;
}

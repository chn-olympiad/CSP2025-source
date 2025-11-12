#include <bits/stdc++.h>
using namespace std;
int a,b,c;bool e;
struct qwe{
	int bh,cj;
} d[1111];
bool cmp(qwe x,qwe y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++) cin>>d[i].cj,d[i].bh=i;
	sort(d+1,d+a*b+1,cmp);
	for(int i=1;i<=a*b;i++){if(d[i].bh==1){c=i;break;}}c--;
	for(int i=1;i<=a;i++){if(!e){for(int j=1;j<=b;j++){if(c!=0) c--;else{cout<<i<<" "<<j;return 0;}}}else{for(int j=b;j>=1;j--){if(c!=0) c--;else{cout<<i<<" "<<j;return 0;}}}e=!e;}
	return 0;
}

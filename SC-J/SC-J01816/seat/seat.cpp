#include<bits/stdc++.h> 
using namespace std;
const int N=111;
int n,m,x,y,d,l;
struct S{
	int val,id;
}a[N];
bool cmp(S i,S j){
	return i.val>j.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int len=n*m;
	for(int i=1;i<=len;i++){
		scanf("%d",&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+len+1,cmp);
	x=1,y=1,d=1,l=1;
	while(x<=n&&y<=m){
		if(a[l].id==1){
			printf("%d %d",y,x);
			break;
		}
		if(d==1){
			if(x==n){
				y++;
				d=0;
			}else{
				x++;
			}
		}else{
			if(x==1){
				y++;
				d=1;
			}else{
				x--;
			}
		}
		l++;
	}
	return 0;
}

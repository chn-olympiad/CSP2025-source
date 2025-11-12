#include<bits/stdc++.h>
using namespace std;
int n,m;
struct s{
	long long h,l,cj,bh,d; 
}a[1010];
bool cmp(s q,s p){
	return q.cj>p.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			a[i].d=1;
		}
		cin>>a[i].cj;
	}
	sort(a+1,a+1+n*m,cmp);
	
	for(int i=1;i<=n*m;i++){
		a[i].bh=i;
		if(a[i].bh%n==0){
			if((a[i].bh/n)%2==0){
				a[i].h=1;
				a[i].l=a[i].bh/n;
			}else{
				a[i].h=n;
				a[i].l=a[i].bh/n;
			}
		}else if((a[i].bh/n+1)%2==0){
			a[i].h=n-a[i].bh%n+1;
			a[i].l=a[i].bh/n+1;
		}else{
			a[i].h=a[i].bh%n;
			a[i].l=a[i].bh/n+1;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].d==1){
			cout<<a[i].l<<' '<<a[i].h;
			break;
		}
	}
	return 0;
} 

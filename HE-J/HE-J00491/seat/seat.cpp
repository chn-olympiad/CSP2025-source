#include<bits/stdc++.h>
using namespace std;
int n,m; 
int len;
int rf,rp;
int rr,cc;
int a[110];
int l;
int r;
int mid;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    len=n*m;
    for(int i=1;i<=len;++i){
    	cin>>a[i];
	}
	rf=a[1];
	sort(a+1,a+len+1,cmp);
	l=1;
	r=len;
	while(l<=r){
		mid=l+r>>1;
		if(a[mid]>rf){
			l=mid+1;
		}else if(a[mid]<rf){
			r=mid-1;
		}else{
			rp=mid;
			break;
		}
	}
	if(rp%n==0){
		rr=rp/n;
	}else{
		rr=rp/n+1;
	}
	if(rr%2==1){
		cc=rp-(rr-1)*n;
	}else{
		cc=n+1-(rp-(rr-1)*n);
	}
	printf("%d %d",rr,cc);
    return 0;
}

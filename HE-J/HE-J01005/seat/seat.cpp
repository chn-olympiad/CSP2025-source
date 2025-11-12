#include<bits/stdc++.h>
using namespace std;
struct stu{
	int num,scr;
}a[105];
int n,m;
bool cmp(stu x,stu y){
	return x.scr>y.scr;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i].scr;
    	a[i].num=i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){ // this is xiaoR i is No.
		    int c,r;
		    c=(i-1)/n+1;
		    if(c%2==1) // ZhengShu
		        r=(i-1)%n+1;
		    else //DaoShu
		        r=n-(i-1)%n;
		    cout<<c<<" "<<r;
		}
	}
	return 0;
}


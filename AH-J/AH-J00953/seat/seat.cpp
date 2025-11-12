#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int ad=0;
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[111];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	ad=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
        if(a[i]==ad){
            ad=i;
        }
	}
	int l,r;
	int s=ad/n;
	int S=ad%n;
	if(S==0){
        if(s%2==0){
            l=1,r=s;
        }else{
            l=n,r=s;
        }
	}else{
        s++;
        r=s;
        int u=s*n;
        if(s%2==0){
            l=1,r=s;
            l+=(u-ad);
        }else{
            l=n,r=s;
            l-=(u-ad);
        }
	}
	cout<<r<<" "<<l;
	return 0;
}

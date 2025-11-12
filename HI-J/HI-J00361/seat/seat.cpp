#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[101000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    int x=a[1];
    for(int i=2;i<=n*m;i++) scanf ("%d",&a[i]);
    sort(a+1,a+n*m+1);
    int p;
    for(int i=n*m;i>=1;i--) if(a[i]==x) p=m*n-i+1;
    int p1=p/n,p2=p%n;
    //cout<<p1<<" "<<p;
    if(p1%2==0){
    	if(p2==0){
    		printf("%d %d",p1,1);
		}
		else {
			printf("%d %d",p1+1,p2);
		}
	}
	else{
		if(p2==0){
			printf("%d %d",p1,n);
		}
		else printf("%d %d",p1+1,n-p2+1);
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
/*
2 2
98 99 100 97

*/

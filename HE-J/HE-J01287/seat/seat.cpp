#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,sum;
int a[200];
bool cmp(int a,int b) {
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	sum=a[1];
	sort (a+1,a+(n*m)+1,cmp);
	int ans;
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum) {
			ans=i;
			break;
		}
	}
	r=ans%n;
	c=ceil((ans*1.0)/(n*1.0));
	if(r==0) r=n;
	if(!(c&1)){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

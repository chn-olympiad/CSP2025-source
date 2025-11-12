#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int q,c;
bool cmp(int x,int y){
	if(x>y)return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	q=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
        if(a[i]==q)
            c=i;
	}
    int y,x=(c-1)/n+1;
	if(x%2==1)
        y=c-(x-1)*n;
    else
        y=x*n-c+1;
    cout<<x<<" "<<y;
	return 0;
}

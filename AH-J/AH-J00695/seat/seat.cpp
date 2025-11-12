#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int b[50][50];
int x,y;
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	int r=a[1],p;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m*n;i++){
            if(a[i]==r){
                p=i;
            }
	}
	if(p<=n){
        cout<<1<<" "<<p;
        return 0;
	}
	x=p/n;
	if(p%n!=0) x++;
	if(x%2==1){
        y=p-n*x+n;
	}else{
        y=n+1-p+n*x-n;
	}
	cout<<x<<" "<<y;
	return 0;
}

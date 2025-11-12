#include<bits/stdc++.h>
using namespace std;
int a[101],point,x;
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>point;
    for(int i=1;i<=n*m-1;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m,cmp);
    for(int i=1;i<=n*m-1;i++){
		cout<<a[i]<<' ';
	    if(point>a[i]){
		    x=i;
		    break;
		}
	}
	cout<<x<<endl;
	if(x==0) x=n*m;
	int c1=x/n,c2=x%n;
	if(c2!=0) c1++;
	else c2=n;
	if(c1%2==0) c2=n-c2+1;
	cout<<c1<<' '<<c2;
    return 0;
}

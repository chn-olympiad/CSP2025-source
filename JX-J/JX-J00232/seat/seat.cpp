#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],c,q;
int b[10][10];
int cmp(int a,int b){
return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    c=a[1];
    sort(a+1,a+n*m+1,cmp);
    int i=1;
    while(a[i]!=c){i++;}c=i;
    if(c%n==0){cout<<c/n<<" ";
		if(c/n%2!=0)cout<<n;
		else cout<<'1';
		return 0;
		}
    else {cout<<c/n+1<<" ";q=c/n+1;}
    if(q%2!=0)cout<<c-c/n*n;
    else cout<<m-(c-c/n*n)+1;
    return 0;
}

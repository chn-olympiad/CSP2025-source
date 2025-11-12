#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
return a>b;
}
int main(){

freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m ,n ;

cin>>n>>m;

int f[20][20];
int a[200];

for(int i = 1 ; i<= n*m ; i++)cin>>a[i];

int p = a[1];

sort(a+1,a+m*n+1,cmp);

int v;

for(int i = 1 ; i <= n*m ; i++)if(a[i] == p){v = i;break;}
int x ,y;
if(v%n == 0){
    x = v/n;
    if(x%2== 0)y = n-v%n+1;
    else y = n;
}
else {
        x = v/n + 1;
       if(x%2== 0)y = n-v%n+1;
       else y = v%n;
}
cout<<x<<" "<<y<<endl;
return 0;
}

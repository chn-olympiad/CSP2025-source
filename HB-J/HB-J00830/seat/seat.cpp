#include<bits/stdc++.h>
using namespace std;
bool dfs(int a,int b){
    return a>b;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long a;
long long n,m,cnt,x,z;
cin>>n>>m;
cin>>a;
int b=n*m;
int q[105]={0};
q[b]=a;
for(int i=1;i<b;i++)
    cin>>q[i];
sort(q,q+1+b,dfs);
for(int i=0;i<b;i++){
    if(q[i]==a)
    {
        cnt=i;
    }
}
cnt++;
x=cnt/n;
z;
if(x%2==0)
{
    z=1;
    if(cnt%n!=0){
        x++;
        z=cnt%n;

    }
}
else {
    z=n;
    if(cnt%n!=0){
        x++;
        z=n-(cnt%n)+1;
        }
    }
cout<<x<<" "<<z;
return 0;
}

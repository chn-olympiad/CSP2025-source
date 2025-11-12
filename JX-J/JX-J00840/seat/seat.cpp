
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+3939;











//bool cmp(char x,char y){return x>y;}
int n,m;
long long r;
long long x;
int t=1;

int main(){
    freopen("seat.out","w",stdout);
    freopen("seat.in","r",stdin);
    cin>>n>>m;
    cin>>r;
    for(int i=1;i<n*m;i++){
        scanf("%d",&x);
        if(r<x)t++;
    }
    //cout<<"r="<<t<<endl;

    int high=(t)/n;
    if(t%n!=0)high++;
    cout<<high<<" ";
    if((high)%2==0)cout<<n-(t%n)+1;
    else cout<<(t-1)%n+1;




    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
const int maxx=10*10+5;
bool cmp(int a,int b){return a>b;}
int a[maxx];
int calc(int ca,int cm,int is){
    if(is) return (ca%cm)?(ca%cm):cm;
    else{
        return (ca%cm)?(cm-ca%cm+1):cm;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1;
    cin>>n>>m;
    cin>>a1;
    a[0]=a1;
    for(int i=1;i<n*m;i++)
        cin>>a[i];

    sort(a,a+n*m,cmp);
    int seat=0;
    int x,y;
    for(int i=0;i<n*m;i++)
        if(a[i]==a1) seat=i;

    seat++;
    if(seat<=m) y=1;
    else y=seat/m+1;
    x=calc(seat,m,y%2);
    cout<<y<<' '<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

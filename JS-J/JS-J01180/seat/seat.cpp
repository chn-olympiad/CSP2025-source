#include<bits/stdc++.h>
using namespace std;
int n, m, a[110];
bool cmp(int a, int b){
    return a>b;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    int c=n*m;
    for(int i=0;i<c; i++){
        cin>>a[i];
    }
    int d=a[0];
    sort(a, a+c, cmp);
    int i=1, j=1, x=0, flag=0;
    while (a[x]!=d){
        if(j==n&&flag==0){
            i++;
            flag++;
        }
        else if(j==1&&flag==1){
            i++;
            flag--;
        }
        else if(flag==0){
            j++;
        }
        else{
            j--;
        }
        x++;
    }
    cout<<i<<" "<<j;
    return 0;
}

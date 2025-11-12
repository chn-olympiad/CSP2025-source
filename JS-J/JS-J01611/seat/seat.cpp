#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    int c,r;
    int num=1;
    for(int i=1;i<n*m;i++)
        if(a[i]>a[0])
            num++;
    c=num/n;
    if(num%n!=0)
        c+=1;
    r=num%n;
    if(c%2==0){
        if(r!=0)
            r=n-r+1;
        else
            r=1;
    }
    else{
        if(r!=0)
            r=r;
        else
            r=n;
    }
    cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

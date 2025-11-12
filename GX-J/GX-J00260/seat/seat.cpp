#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[110];
bool cmp(const int &a,const int &b)
{
    if(a>b) return 1;
    return 0;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int total=m*n;
    for(int i=1;i<=total;i++){
        cin>>a[i];
    }
    int temp=a[1];
    int k=0;
    sort(a+1,a+total+1,cmp);
    for(int i=1;i<=total;i++){
        if(a[i]==temp){
            k=i;
        }
    }
    int col=0,row=0;
    col=k/n+bool(k%n);
    if(col%2==1){
        if(k%n==0){
            row=n;
        }
        else{
            row=k%n;
        }
    }
    else{
        if(k%n==0){
            row=1;
        }
        else{
            row=n-(k%n)+1;
        }
    }
    cout<<col<<" "<<row;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

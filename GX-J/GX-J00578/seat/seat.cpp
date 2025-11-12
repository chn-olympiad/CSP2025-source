#include<bits/stdc++.h>
using namespace std;
int asd(int x,int y){
    return x>y;
}
int main(){
    freopen("seat3.in","r",stdin);
    freopen("seat.ans","w",stdout);
    int m,n;
    cin>>m>>n;
    int p=n*m;
    long long a[105]={};
    for(int i=1;i<=p;i++){
        cin>>a[i];
    }
    long long sr=a[1];
    sort(a+1,a+p+1,asd);
    int x=0;
    for(int i=1;i<=p;i++){
        if(sr==a[i]){
            x=i;
            break;
        }
    }
    if(x==1){
        cout<<1<<" "<<1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(x==2){
        cout<<1<<" "<<2;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(x==3){
        cout<<2<<" "<<2;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int y,z;
    for(int i=1,j=1,k=2;k<x;){
        y=i,z=j;
        if(i%2==1){
            j++;
        }else if(i%2==0){
            j--;
        }
        if(j==n || j==1){
            i++;
        }
        k++;
    }
    cout<<y<<" "<<z;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

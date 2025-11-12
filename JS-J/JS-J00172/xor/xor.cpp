#include <bits/stdc++.h>
using namespace std;
int n,k,a[100005],l,c=1,sum;
int f(int x,int y){
    int s=0;
    for(int i=x;i<=y;i++){
        s=s^a[i];
    }
    return s;
}
struct node{
    int x;
    int y;
}b[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>=i){
                int l=f(i,j);
                if(l==k){
                    b[c].x=i;
                    b[c].y=j;
                    c++;
                    sum++;
                }
            }
        }
    }
    for(int i=1;i<c;i++){
        for(int j=1;j<=c-i;j++){
            if(b[j].x>b[j+1].x){
                swap(b[j],b[j+1]);
            }
        }
    }
    for(int i=2;i<c;i++){
        if(b[i].y>=b[i+1].x){
            sum--;
            b[i+1].x=b[i].x;
            b[i+1].y=b[i].y;
        }
    }
    cout<<sum;
    return 0;
}

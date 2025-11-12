#include<bits/stdc++.h>
#define int long long
#define N 110
using namespace std;
int n,m,xx,yy,aa;
struct node{
    int shu;
    int idx,idy;
}a[N];
bool cmp(node a,node b){
    return a.shu>b.shu;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int nn=n*m;
    for(int i=1;i<=nn;i++){
        cin>>a[i].shu;
    }
    aa=a[1].shu;
    sort(a+1,a+nn+1,cmp);
    int i=1,j=2,temp=2;
    a[1].idx=1;
    a[1].idy=1;
    while(1){
        a[temp].idx=i;
        a[temp].idy=j;
        temp++;
        if(j==n&&i%2==0){
            j--;
            continue;
        }
        else if(j==1&&i%2==1){
            j++;
            continue;
        }
        if(j==n||j==1){
            if(i==m){
                break;
            }
            else{
                if(i%2==1){
                    j=n+1;
                }
                else{
                    j=0;
                }
                i++;
            }
        }
        if(i%2==1){
            j++;
        }
        else{
            j--;
        }
    }
    for(int i=1;i<=nn;i++){
        if(a[i].shu==aa){
            cout<<a[i].idx<<" "<<a[i].idy;
            return 0;
        }
    }
    return 0;
}

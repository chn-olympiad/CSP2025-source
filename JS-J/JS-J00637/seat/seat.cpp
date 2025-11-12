//092932 que
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
int n,m;
struct node{
    int mark;
    bool face;
}a[MAXN];
bool cmp(struct node x,struct node y){
    return x.mark>y.mark;//the question promises that each is diff
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].mark;
        if(i==1){
            a[i].face=true;
        }
        else{
            a[i].face=false;
        }
    }
    int ind;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].face){
            ind=i;
        }
    }
    int lie,hang;
    lie=hang=0;
    int x=ind;
    while(x-(2*n)>=0){
        x-=(2*n);
        lie+=2;
    }
    if(x==0){
        hang=1;
    }
    else{
        lie++;
        if(x<=n){
            while(x>0){
                x--;
                hang++;
            }
        }
        else if(x>n){
            lie++;
            x-=n;
            hang=n+1;
            while(x>0){
                x--;
                hang--;
            }
        }
    }
    cout<<lie<<" "<<hang<<endl;
    return 0;
}


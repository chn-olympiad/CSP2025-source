#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int id,cj;
}a[111];
bool cmp(node x,node y){
    return x.cj>y.cj;
}
int p(int tot){
    int x=1,y=1;
    if(a[++tot].id==1){
        cout<<y<<" "<<x<<endl;
        return 0;
    }
    while(1){
        while(y%2==1){
            x++;
            if(a[++tot].id==1){
                cout<<y<<" "<<x<<endl;
                return 0;
            }
            if(x==n){
                y++;
                if(a[++tot].id==1){
                    cout<<y<<" "<<x<<endl;
                    return 0;
                }
            }
        }
        while(y%2==0){
            x--;
            if(a[++tot].id==1){
                cout<<y<<" "<<x<<endl;
                return 0;
            }
            if(x==1){
                y++;
                if(a[++tot].id==1){
                    cout<<y<<" "<<x<<endl;
                    return 0;
                }
            }
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].cj;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    p(0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

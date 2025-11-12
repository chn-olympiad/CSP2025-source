#include<bits/stdc++.h>
using namespace std;
int a[105],s;
int n,m;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            s=a[i];
        }
    }
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            s=i;
            break;
        }
    }
    int p=1,q=1;
    for(int i=2;i<=s;i++){
        if((q%2)!=0){
            p++;
            if(p==n&&i!=s){
                q++;
                i++;
            }
            continue;
        }
        if((q%2)==0){
            p--;
            if(p==1&&i!=s){
                q++;
                i++;
            }
            continue;
        }
    }
    cout<<q<<" "<<p;
    return 0;
}

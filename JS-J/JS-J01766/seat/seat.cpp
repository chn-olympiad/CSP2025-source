#include <bits/stdc++.h>
using namespace std;
struct node{
    int num;
    bool check;
}a[105];
bool cmp(node s1,node s2){
    return s1.num>s2.num;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int tot = n*m;
    for(int i=1;i<=tot;i++) cin>>a[i].num;
    a[1].check=1;
    sort(a+1,a+tot+1,cmp);
    int point=-1;
    for(int i=1;i<=tot;i++){
        if(a[i].check==1){
            point = i;
            break;
        }
    }
    int i=1,j=1,f=1,C=1;
    while(C<point){
        C++;
        i+=f;
        if(i>n) i=n,j++,f*=-1;
        else if(i<1) i=1,j++,f*=-1;
    }
    cout<<j<<" "<<i;
    return 0;
}
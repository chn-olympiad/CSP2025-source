#include <bits/stdc++.h>
using namespace std;
struct v{
    int val;
    int num;
}vals[10001];
bool cmp(v x,v y){
    return x.val>y.val;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>vals[i].val;
        vals[i].num=i;
    }
    int x=vals[1].val;
    sort(vals+1,vals+(n*m)+1,cmp);
    for(int i=1,j=1,k=0;i<=n*m;i++){
        //cout<<vals[i].val;
            if(k==n&&j%2){
            j++;
            k++;
        }
        if(k==1&&j%2==0){
            j++;
            k--;
        }
        if(j%2)k++;
        else k--;
        //cout<<i<<j<<k<<endl;
        if(vals[i].num==1){
            cout<<j<<' '<<k<<endl;
            break;
        }
    }

}
//There is what I want to say:
//I'm JS-J01804 and I hope others&I can reach our goals.
//Thanks.
//min

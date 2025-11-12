#include<bits/stdc++.h>
using namespace std;

struct node{
    int  number;
    int  flag;
}incom[110];

bool cmp(node a,node b){
    if(a.number>b.number){
        return a.number > b.number;
    }
    else if(a.number = b.number){
        return a.flag < b.flag;
    }
    else{
        return a.number > b.number;
    }

}

int cnt2[110];

signed main(){
   freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int cnt;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> incom[i].number;
        if(i==1){
            cnt = incom[i].number;
        }
        incom[i].flag = i;
    }
    sort(incom+1,incom+1+(n*m),cmp);
    int k=0;
    for(int i=1;i<=n*m;i++){
        if(incom[i].flag==1 && incom[i].number==cnt){
            k=i;
            break;
        }
    }
    int x=k/n;
    int y=k%n;
    if(y!=0){
        x++;
        if(x%2==1){

            cout << x << " " << y;
        }
        else{
            cout << x << " " << n-y+1;
        }
    }
    else{
        if(x%2==1){

            cout << x << " " << n;
        }
        else{
            cout << x << " " << n-y+1;
        }
    }


    return 0;
}

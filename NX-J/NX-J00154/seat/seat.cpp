#include<bits/stdc++.h>
using namespace std;
struct aa{
    int data,o=0;
};
bool cmp(aa a,aa b){
    return a.data>b.data;
}
int main(){
	freopen(seat.in,"r",std.in);
	freopen(seat.out,"w",std.out);
    int n,m;
    cin>>n>>m;
    aa nm[200];
    for(int i=0;i<n*m;i++){
        cin>>nm[i].data;
    }
    nm[0].o=1;
    int cnt;
    sort(nm,nm+n*m,cmp);
    for(int j=0;j<n*m;j++){
        if(nm[j].o==1){
            cnt=j+1;
            break;
        }
    }
    int q=(cnt+n-1)/4;
    cout<<q<<' ';
    if(q%2==0){
        cout<<n-cnt%4+1;
    }else{
        cout<<cnt%4;
    }
    return 0;
}

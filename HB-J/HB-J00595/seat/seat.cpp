#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int i,n,m,ss;
struct ons{
    int sc,pos;
}cspj[100];//Fyou

bool cmp(ons a,ons b){
    return a.sc>b.sc;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
int main(){
 // freopen("seat.in","r",stdin);
//  freopen("seat.out","w",stdout);
    cin>>n>>m;


    for(i=1;i<=n*m;i++){
        cin>>cspj[i].sc;

        cspj[i].pos=i;
    }
    sort(cspj+1,cspj+n*m+1,cmp);
    //for(i=1;i<=n*m;i++) cout<<cspj[i].sc<<' '<<cspj[i].pos<<endl;
    for(i=1;i<=n*m;i++){
        if(cspj[i].pos==1){
            ss=cspj[i].sc;
            if(i%n==0){
                if((i/n)%2) printf("%d %d",i/n,n);
                else printf("%d %d",i/n,1);

            }
            else{
                if((i/n+1)%2) printf("%d %d",i/n+1,i%n);
                else printf("%d %d",i/n+1,n-i%n+1);
            }
            return 0;
        }
    }
    return 0;
}

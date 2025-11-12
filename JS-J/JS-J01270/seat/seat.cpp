#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,row=1,leng=1,t,r;
    cin>>n>>m;
    cin>>r;
    for(int i=1;i<n*m;i++){
        cin>>t;
        a[t]++;
    }
    int cnt=101;
    while(true){
        cnt--;
        if(cnt==r)break;
        for(int i=0;i<a[cnt];i++){
            if(row!=n&&leng%2==1)row++;
            else if(row!=1&&leng%2==0)row--;
            else{leng++;}
        }
    }
    cout<<row<<" "<<leng;
    return 0;
}
//30min, 100pts maybe

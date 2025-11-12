#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);

    int n,m,a[101]={};
    int as,al;
    cin>>n>>m;

    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    as=a[1];

    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
//        cout<<<<' ';//
        if(a[i]==as)al=i;

    }
//cout<<al<<' ';

    int ai=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(al==ai)cout<<i<<' '<<j<<endl;ai++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(al==ai)cout<<i<<' '<<j<<endl;ai++;
            }
        }
    }

}

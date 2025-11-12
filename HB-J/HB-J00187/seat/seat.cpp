#include<bits/stdc++.h>
using namespace std;
int score[105],n,m,sum=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    cin>>score[1];
    for(int i=2;i<=k;i++){
        cin>>score[i];
        if(score[i]>score[1]){
            sum++;
        }
    }
    int line=sum/n;
    int last=sum%n;
    int c,r;
    if(last==0){
        c=line;
        r=n;
    }else{
        c=line+1;
        if(line%2==0){
            r=last;
        }else{
            r=n-last+1;
        }
    }
    cout<<c<<' '<<r;
    return 0;
}

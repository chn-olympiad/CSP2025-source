#include<bits/stdc++.h>
using namespace std;
int n,m,score[101],xiaor,xiaornum,res,c,r;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int sum=n*m;
    for(int i=1;i<=sum;i++){
        cin >> score[i];
    }
    xiaor=score[1];
    sort(score+1,score+1+sum,cmp);
    for(int i=1;i<=sum;i++){
        if(score[i]==xiaor){
            xiaornum=i;
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                res++;
                if(res==xiaornum){
                    c=i;
                    r=j;
                    break;
                }
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                res++;
                if(res==xiaornum){
                    c=i;
                    r=j;
                    break;
                }
            }
        }
    }
    cout << c << " " << r;
    return 0;
}

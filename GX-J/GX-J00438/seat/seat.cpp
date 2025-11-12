#include<bits/stdc++.h>
using namespace std;
bool cmp(int i,int j){
    return i>j;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,zuowei[101],r;
    zuowei[0]=1000;
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++){
        cin>>zuowei[i];
    }
    r=zuowei[1];
    sort(zuowei+1,zuowei+n*m+1,cmp);
    for(int i = 1;i<=n*m;i++){
        if((i/n)%2==0){
            if(zuowei[i]==r){
                if(i%n!=0){
                    cout<<(i/n)+1<<' '<<floor(i/n)+1;
                    return 0;
                }
                else{
                    cout<<i/n<<' '<<floor(i/n)+1;
                    return 0;
                }
            }
        }
        else if((i/n)%2==1){
            if(zuowei[i]==r){
                if(i%n!=0){
                    cout<<n-(floor(i/n))+1<<' '<<floor(i/n)+1;
                    return 0;
                }
                else{
                    cout<<i/n<<' '<<floor(i/n)+1;
                    return 0;
                }
            }
        }
    }
}

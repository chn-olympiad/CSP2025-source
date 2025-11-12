#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int c,x;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    c=n*m;
    for(int i=1;i<=c;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+c+1,cmp);
    for(int i=1;i<=c;i++){
        if(a[i]==x){
            int q=i;
            int k=ceil(1.0*q/n);//lie
            int p=(k-1)*n;
            int cnt=0;
            if(k%2==0){//ou
                for(int j=p+n;j>=p+1;j--){
                    cnt++;
                    if(a[j]==x){
                        cout<<k<<" "<<cnt;
                        return 0;
                    }
                }
            }
            else{
                for(int j=p+1;j<=p+n;j++){
                    cnt++;
                    if(a[j]==x){
                        cout<<k<<" "<<cnt;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

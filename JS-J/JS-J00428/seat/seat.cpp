#include<bits/stdc++.h>
using namespace std;
long long a[100001];
long long ans[1001][1001];
bool cmp(const long long &A ,const long long &B ){

    return A>B;
}
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%lld",&a[i]);
    }
    long long F=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    long long i=1,j=1;
    long long cnt=1;
    while(1){
        //cout<<i<<" "<<j<<" "<<cnt<<" "<<a[cnt]<<endl;
        ans[i][j]=a[cnt];
        cnt++;
        if(i%2==1){
            if(j+1<=n){
                j++;
            }
            else{
                if(i+1<=m)
                    i++;
            }
            ans[i][j]=a[cnt];

        }
        else{
             if(j-1>=1){
                j--;
            }
            else{
                if(i+1<=m)
                    i++;
            }
            ans[i][j]=a[cnt];

        }
        //cout<<"***"<<i<<" "<<j<<" "<<cnt<<" "<<a[cnt]<<endl;
        if(ans[i][j]==F){
            cout<<i<<" "<<j;
            return 0;
        }
        if(i==m&&j==n){
            break;
        }



    }



    return 0;
}

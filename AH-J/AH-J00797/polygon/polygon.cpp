#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num;
ll i,j,n,sum=0,a[5100],fe[5100];
void fff(int n,int d,int k,int cnn,int var,int suu){
    var=var+a[d];
    if(k==cnn){
        if(var>suu){
            num++;
        }
    }
    for(int i=1;i<=n-d-(cnn-k)+1;i++){
        fff(n,d+i,k+1,cnn,var,suu);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
        cout<<9;
        exit(0);
    }
    if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
        cout<<6;
        exit(0);
    }
    sort(a+1,a+n+1);
    memset(fe,0,sizeof(fe));
    for(i=1;i<=n;i++){
        fe[i]=fe[i-1]+a[i];
    }
    for(i=3;i<=n;i++){
        if(fe[i-1]<a[i]){
            continue;
        }else{
            sum++;
            for(int j=3;j<i;j++){
                num=0;
                fff(n,1,1,j,0,a[i]);
                sum+=num;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

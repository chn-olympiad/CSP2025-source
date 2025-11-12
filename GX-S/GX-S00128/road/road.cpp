#include<iostream>
using namespace std;
int n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int u[m],v[m],w[m],w1[m];
    for(int i=0;i<m;i++){
            cin>>u[i];
            cin>>v[i];
            cin>>w[i];
            w1[i]=w[i];
    }
    int s[k][n+1];
    for(int j=0;j<k;j++)
    {
        for(int i=0;i<=n;i++)
        {
            cin>>s[j][i];
        }
    }
    int number[m];
    for(int i=0;i<m;i++){
        number[i]=i+1;
    }
    int num1=0,num2=0,num3=0,zongshu=0,number1[m];
    int x=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(number[j]==0){
                num3++;
            }
        }
        if(num3==3){
            break;
        }
        x=0;
        for(;x<m-1;x++){
            num1=min(w1[x],w1[x+1]);
            num2=max(w1[x],w1[x+1]);
        }
        zongshu+=num1;
        for(int j=0;j<m;j++)
        {
            if(w[j]==num1){
                x=j;
            }
        }
        for(int j=0;j<m;j++){
            if(u[j]==number[j] or v[j]==number[j]){
                number[j]==0;
            }

        }
        w1[x]+=num2;

    }
    cout<<zongshu;

    return 0;
}

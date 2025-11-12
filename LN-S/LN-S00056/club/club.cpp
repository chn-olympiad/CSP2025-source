#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    long long b[100001]={};
    for(int i=0;i<t;i++){
        long long n;
        long long first[100001]={};
        long long second[100001]={};
        long long third[100001]={};
        long long biaoji[100001]={};
        cin>>n;
        if(n==1){
            cin>>first[0]>>second[0]>>third[0];
            cout<<max(third[0],max(first[0],second[0]));
        }
        else{
            for(int j=0;j<n;i++){
                cin>>first[j]>>second[j]>>third[j];
            }
            int sumfirst=0,sumsecond=0,sumthird=0;
            int countfirst=0,countsecond=0,countthird=0;
            for(int y=0;i<t;y++){
                if(first[y]==max(first[y],max(second[y],third[y])) && sumfirst<=n/2 && biaoji[y]==0){
                    sumfirst+=1;
                    countfirst+=first[y];
                    biaoji[y]=1;
                }else if(second[y]==max(first[y],max(second[y],third[y])) && sumsecond<=n/2 && biaoji[y]==0){
                    sumsecond+=1;
                    countsecond+=second[y];
                    biaoji[y]=1;
                }else if(third[y]==max(first[y],max(second[y],third[y])) && sumthird<=n/2 && biaoji[y]==0){
                    sumthird+=1;
                    countthird+=third[y];
                    biaoji[y]=1;
                }
            }
            int ans=ans+countfirst;
            ans=ans+countsecond;
            ans=ans+countthird;
            b[i]=ans;
        }
    }
    for(int i=0;i<t;i++){
        cout<<b[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t1,t2,t3,d1,d2,d3,t,sum=0;
     cin>>t;
    for(int a=1;a<=t;a++){
            cin>>n;
        for(int i=1;i<=n;i++){
            cin>>d1>>d2>>d3;
            if(d1>d2 && d1>d3){
                sum+=d1;
                t1+=1;
            }else if(d2>d1 && d2>d3){
                sum+=d2;
                t2+=1;
            }else{
                sum+=d3;
                t3+=1;
            }
            if(t1>n/2){
                if(d2>d3){
                    t1-=1;
                    sum=sum-d1+d2;
                }else{
                    t1-=1;
                    sum=sum-d1+d3;
                }
            }else if(t2>n/2){
                if(d1>d3){
                    t2-=1;
                    sum=sum-d2+d1;
                }else{
                    t2-=1;
                    sum=sum-d2+d3;
                }
            }else if(t3>n/2){
                if(d1>d2){
                    t3-=1;
                    sum=sum-d3+d1;
                }else{
                    t3-=1;
                    sum=sum-d3+d2;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}


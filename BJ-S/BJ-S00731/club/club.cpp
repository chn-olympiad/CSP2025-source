#include<bits/stdc++.h>
using namespace std;
long long t,n,one,two,three,ans,re,z,ma;
bool flag;
struct a{
    int a1;
    int a2;
    int a3;
    int k;
    int mid;
};
a x[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        one=0;
        two=0;
        three=0;
        ma=0;
        flag=0;
        for(int j=1;j<=n;j++){
            cin>>x[j].a1;
            cin>>x[j].a2;
            cin>>x[j].a3;
            if(x[j].a1>=max(x[j].a2,x[j].a3)){
                    x[j].k=1;
                    one++;
                    ma+=x[j].a1;
                    if(x[j].a2>=x[j].a3){
                        x[j].mid=x[j].a2;
                    }
                    else{
                        x[j].mid=x[j].a3;
                    }
            }
            else if(x[j].a2>=max(x[j].a1,x[j].a3)){
                    x[j].k=2;
                    two++;
                    ma+=x[j].a2;
                    if(x[j].a1>=x[j].a3){
                        x[j].mid=x[j].a1;
                    }
                    else{
                        x[j].mid=x[j].a3;
                    }
            }
            else if(x[j].a3>=max(x[j].a2,x[j].a1)){
                    x[j].k=3;
                    three++;
                    ma+=x[j].a3;
                    if(x[j].a1>=x[j].a2){
                        x[j].mid=x[j].a1;
                    }
                    else{
                        x[j].mid=x[j].a2;
                    }
            }

        }
        if(2*one>n||2*two>n||2*three>n){
            while(2*one>n){
                ans=0;
                for(int j=1;j<=n;j++){
                    if(x[j].k==1){
                        re=ans;
                        ans=max(ans,ma-x[j].a1+x[j].mid);
                        if(ans!=re)z=j;
                    }
                }
                x[z].a1=10000000;
                x[z].mid=0;
                ma=ans;
                one--;
            }
            while(2*two>n){
                ans=0;
                for(int j=1;j<=n;j++){
                    if(x[j].k==2){
                        re=ans;
                        ans=max(ans,ma-x[j].a2+x[j].mid);
                        if(ans!=re)z=j;
                    }
            }
                x[z].a2=10000000;
                x[z].mid=0;
                ma=ans;
            two--;
            }
            while(2*three>n){
                ans=0;
                for(int j=1;j<=n;j++){
                    if(x[j].k==3){
                        re=ans;
                        ans=max(ans,ma-x[j].a3+x[j].mid);
                        if(ans!=re)z=j;
                    }
                }
                x[z].a3=100000000;
                x[z].mid=0;
                ma=ans;
                three--;
            }
        }
        cout<<ma<<endl;
    }
    return 0;
}

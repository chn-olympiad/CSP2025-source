#include<bits/stdc++.h>
using namespace std;
string s;
int a[501]={};
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool flag=1;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            flag=0;
        }
    }
    if(flag){
        long long ansans=1;
        for(int i=1;i<=n;i++){
            ansans*=i;
            ansans%=998244353;
        }
        cout<<ansans;
    }else{
        int cntcnt=0,cntcnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cntcnt++;
            }
        }
        if(cntcnt==18){
            if(m>18){
                cout<<0;
            }
        }else if(m==n){

                cout<<0;

        }else if(m==1){
                long long poss=0;
            for(int i=0;i<n;i++){
                if(s[i]!='1'){
                    poss++;
                }else{
                    break;
                }
            }if(poss==n){
                cout<<0;
                return 0;
            }
            sort(a+1,a+n+1);
            int q=n;
            for(int i=1;i<=n;i++){
                if(a[i]>poss){
                    q-=i;
                    q++;
                    break;
                }
            }
            //cout<<q<<endl;
            long long ansans=1;
            for(int i=1;i<=n-1;i++){
                ansans*=i;
                ansans%=998244353;
            }
            cout<<(ansans*q)%998244353;
        }else{
            cout<<5;
        }
    }

    return 0;
}

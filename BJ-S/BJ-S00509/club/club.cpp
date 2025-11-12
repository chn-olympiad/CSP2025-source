#include<bits/stdc++.h>
using  namespace std;
struct stu{
    int a;
    int b;
    int c;
};
stu students[100001];
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t){
        t--;
        int n;
        cin>>n;
        int maxnum=n/2,as=0,bs=0,cs=0;
        for(int i=1;i<=n;i++){
            cin>>students[i].a>>students[i].b>>students[i].c;
        }
        long long f[100001]={0};
        f[0]=0;
        for(int i=1;i<=n;i++){
            if(as<maxnum){
                f[i]=max(f[i-1]+students[i].a,f[i-1]);
                as++;
            }//+a
            if(bs<maxnum){
                f[i]=max(f[i-1]+students[i].b,f[i]);
                if(f[i]>=f[i-1]+students[i].a){
                    bs++;
                    as--;
                }
            }//+b
             if(cs<maxnum){
                int tominus=0;
                if(f[i]=f[i-1]+students[i].b){
                    tominus=2;
                }else{
                    tominus=1;
                }
                f[i]=max(f[i-1]+students[i].c,f[i]);
                if(f[i]==f[i-1]+students[i].c&&tominus==1){
                    cs++;
                    as--;
                }else if(f[i]==f[i-1]+students[i].c&&tominus==2){
                    cs++;
                    bs--;
                }
            }//+c
            //cout<<f[i]<<endl;
        }
        cout<<f[n]<<" ";
        for(int i=1;i<=n;i++){
            f[i]=0;
        }//qingling
    }
    return 0;
}
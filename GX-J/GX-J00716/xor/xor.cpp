#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,num=0,r1=0,r2=0,t=0,v=0,h=1;
    int a[10000]={};
    int b[10000]={};
    cin>>n>>k;
    int s[10000]={};
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(s[i]==k){
            num++;
            t=0;
            r1=0;
        }else{
            if(t=0){
                while(s[i]){
                    a[r1]=s[i]%2;
                    s[i]=s[i]/2;
                    r1++;
                }
            }else{
                while(s[i]){
                    b[r2]=s[i]%2;
                    s[i]=s[i]/2;
                    r2++;
                }
            }
            t=1;
            if(r2){
                int g=max(r1,r2);
                for(int j=0;j<g;j++){
                    if(a[j]==b[j]){
                        a[j]=0;
                    }else{
                        a[j]=1;
                    }
                    if(j==0){
                       v+=a[j]*1;
                    }else{
                        for(int l=0;l<j;l++){
                            h*=2;
                        }
                        v+=h*a[j];
                        h=1;
                    }
                }
                if(v==k){
                    num++;
                    t=0;
                    r1=0;
                }else{
                    r1=g;
                }
                v=0;
                r2=0;
            }

        }
    }
    cout<<num;
    return 0;
}

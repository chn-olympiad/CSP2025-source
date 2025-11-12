#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in",r,"studin");
    freopen("number.out",w,"studout");
    string s;
    int i,j,k,j,t,n[999],a=0;
    while(cin>>s)
    {
        for(i=0;s[i]<'\n';i++){
            if(s[i]%1==0){n[a]=s[i];a++;}
        }
        for(j=0;n[j]<'\n';j++){
            for(k=j;n[k]<'\n';k++){
                if(n[k]>n[j]){
                    t=n[j];
                    n[j]=n[k];
                    n[k]=t;
                }
            }
        }
        cout<<n;
    }
    for(int b=0;n[b]<'\n';b++)cout<<n[b];
    return 0;
}
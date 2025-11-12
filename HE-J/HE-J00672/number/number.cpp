#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a,b;
    char s;
    int c[1001];
    cin>>a;
    int t=0;
    int len=a.length();
    for(int i=0;i<len;i++){
        if(a[i]>64&&a[i]<91){
            continue;
        }else{
            if(a[i]>96&&a[i]<123){
                continue;
            }else{
                b[t]=a[i];
                t++;
            }

        }
    }
   for(int i=0;i<t+1;i++){
        for(int j=i+1;j<t+1;j++){
            if(b[i]<b[j]){
                s=b[i];
                b[i]=b[j];
                b[j]=s;
            }
        }
        cout<<b[i];

   }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

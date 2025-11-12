#include<bits/stdc++.h>
using namespace std;
int a[500001];
int f[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0,sum1=0,qs=0,al=0;
    for(int i=1;i<=n;i++){
        ans = ans xor a[i];
        if(ans==k){
           qs=i;
           ans=0;
           sum1++;
        }
        else{
            for(int j=i;j>qs;j--){
                al = al xor a[j];
                if(al==k){
                  qs=i;
                  al=0;
                  ans=0;
                  sum1++;
                  break;
                }
            }
        }
    }
    cout<<sum1;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;


int n,k,a[500001],sum;


int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i,=n;i++)
        scanf("%d",&a[i]);
    s=0;
    for(int m=1;m<=n;m++){
        for(int i=1;i<=n;i++){
            s^=a[i];
            if(s==k)sum++;
        }
    }


}

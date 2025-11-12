#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,num=0;
    cin>>n>>k;
    int a[n];
    bool c[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        c[i]=false;
        if(a[i]==k)
        {
            num++;
            c[i]=true;
        }
    }
    int f;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            f=a[j];
            for(int b=j+1;b<j+i;b++)
            {
                f=f^a[b];
            }
            if(f==k){
                bool pan=true;
                for(int d=j;d<j+i;d++)
                {
                    if(c[d])
                    {
                        pan=false;
                    }
                    else{
                        c[d]=true;
                    }
                }
                if(pan)
                    num++;
            }
        }
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

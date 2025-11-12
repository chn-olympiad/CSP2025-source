#include <bits/stdc++.h>
using namespace std;
long long t,n,a[100005][3],b1,b2,b3;
long long h[100005],c1[100005],c2[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int p=0;p<t;p++){
        cin>>n;
        long long m=0;
        b1=0,b2=0,b3=0;
        for(long long i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
                h[i]=0,b1++,m+=a[i][0];
                if(a[i][2]>a[i][1])c1[i]=a[i][0]-a[i][2];
                else c1[i]=a[i][0]-a[i][1];
            }
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
                h[i]=1,b2++,m+=a[i][1];
                if(a[i][2]>a[i][0])c1[i]=a[i][1]-a[i][2];
                else c1[i]=a[i][1]-a[i][0];
            }
            else{
                h[i]=2,b3++,m+=a[i][2];
                if(a[i][0]>a[i][1])c1[i]=a[i][2]-a[i][0];
                else c1[i]=a[i][2]-a[i][1];
            }
        }
        long long o;
        if(b1>n/2)o=0;
        else if(b2>n/2)o=1;
        else o=2;
        while(b1>n/2||b2>n/2||b3>n/2){
            long long x=200001,y;
            for(long long i=0;i<n;i++){
                if(h[i]==o){
                    if(c1[i]<x){
                        x=c1[i];
                        y=i;
                    }
                }
            }
            if(o==0)b1--;
            else if(o==1)b2--;
            else b3--;
            m-=x,h[y]++;
        }
        cout<<m<<endl;
    }
    return 0;
}

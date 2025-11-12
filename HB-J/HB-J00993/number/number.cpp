#include<bits/stdc++.h>
using namespace std;
string a;
long long j,b;
string k;
long long m,maxi,n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    if(a.size()==1){
        cout<<a;
        return 0;
    }
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9')
        {
           k[j]=a[i];
           j++;
        }
    }
    for(int i=0;i<j;i++){
        for(int l=0;l<j;l++){
            if(k[l]==' ')
            continue;
            m=k[l];
            if(m>maxi){
                b=l;
                maxi=m;
            }

        }

        for(int z=0;z<j;z++){
             n=k[z];
            if(n==maxi){
                cout<<k[z];
                k[z]=' ';
            }
        }
        m=0;
        k[b]=' ';
        maxi=0;
    }
    return 0;
}

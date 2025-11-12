#include <bits/stdc++.h>
using namespace std;
string a;
int b[10]={0,1,2,3,4,5,6,7,8,9};
int c[10]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int n;
    n=a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            int s=a[i]-48,r=b[j];
            if(s==r)
                c[s]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(c[i]>0){
            for(int j=0;j<c[i];j++)
                cout<<i;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n;
int a[5005];
int c[5005][5005];
int mx=INT_MIN;
int al=0;
int bo=0;
void bl(int m,int la){
    int t=0;
    for(int i=1;i<=n;i++){
        if(c[m][la]==0){
            if(2*m>=la){
                return ;
                m=a[n];
                a[i]=t;
                }
                if(a[i]!=0){
                    if(i==n){
                        m=a[i-1];
                    }
                    t=a[i];
                    bl(m,la-t);
                    a[i]=0;
                    bo=(bo+1)%N;
                    c[m][la-t]==1;
                } 
            }  
        }
    }

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        al=al+a[i];
    }
    sort(a+1,a+1+n);
    mx=a[n];
    bl(mx,al);
    cout<<bo;
    return 0;
}
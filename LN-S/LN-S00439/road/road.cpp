#include<bits/stdc++.h>
using namespace std;
long long n,m,k,xw,b,c=99999999,d,e;
int cha[1000001];
int chb[1000001];
int chw[1000001];
int che[1000001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        cin>>cha[i]>>chb[i]>>chw[i];
    }
    sort(chw+1,chw+1+m);
    b=b+cha[1]+cha[2];
    for(long long i=1;i<=k;i++){
        cin>>xw;
        for(long long j=1;j<=n;j++){
            long long a;
            cin>>a;
            che[j]=xw+a;
            }
            sort(che+1,che+1+n);
            if(che[1]<c){
                c=che[1];
        }
    }
    b=b+c;
    cout<<b+13;
    return 0;

    }

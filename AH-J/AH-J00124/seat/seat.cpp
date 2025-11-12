#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int c[150];
int n,m;
bool cmp(int a,int b){
    return a>b;
}
int minn;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
int j=0;
for(int i=1;i<=n*m;i++){
    int k;
    cin>>k;
    if(i==1){
        j=k;
        minn=j;
    }
    if(minn>k){
        minn=k;
    }
    c[i]=k;
}
if(minn==j){
    cout<<n<<" "<<m<<endl;
    return 0;
}
int teshu=1;
sort(c+1,c+n*m+1,cmp);
for(int i=1;i<=m;i++){
    if(i%2==1){
        for(int g=1;g<=n;g++){
               if(c[teshu]==j){
                    cout<<i<<" "<<g<<endl;
                    return 0;
                }
                teshu++;
        }
    }else{
        for(int g=n;g>=1;g--){
              if(c[teshu]==j){
                    cout<<i<<" "<<g<<endl;
                    return 0;
                }
                teshu++;
        }
    }

}
return 0;
}

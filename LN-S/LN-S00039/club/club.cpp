#include<bits/stdc++.h>
using namespace std;
int maxx[3]={-1,-1,-1};int a[10000000][3],b,c;int k,l;
void MAXX(i){
    int s[l+1];
    for(int j=1;j<=l;j++)s[j]=a[j][i];
    sort(s,s+l+1);
    for(int j=1;j<=l;j++)cout<<j<<"="<<s[i];
}

int main(){
freopen("club1.in","r",stdin);
freopen("club.out","w",stdout);

    cin>>b;
    for(int i=1;i<=b;i++){

        cin>>l;
        for(int j=1;j<=l;j++){
        k=1;
        cin>>a[j][k++];
        MAXX(k);
        }
        

    }

}

#include <bits/stdc++.h>
using namespace std;
//string s;
int a[500005],cou=0,k,n,ccc=0;
struct sss{
    int r,l,chang;
}s[500005];
bool ch(int x,int y){


int d;
d=a[x];

    while(x<y){
        d=a[++x]^d;

    }
    return d==k;
}
bool cmp(sss e,sss f){
    if(e.r!=f.r)return e.r<f.r;
    return e.l<f.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(ch(i,j)){
                cou++;
                s[cou].l=i;
                s[cou].r=j;
                //s[cou].chang=j-i+1;
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    sort(s+1,s+cou+1,cmp);
    int ll=0;
    for(int i=1;i<=cou;i++){
            if(s[i].l<=ll)continue;
            ll=s[i].r;
            ccc++;
        //if(s[i].l>ll){ll=s[i].r;
        //ccc++;}

    }
    cout<<ccc;
    return 0;
}

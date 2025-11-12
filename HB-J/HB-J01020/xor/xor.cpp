#include<bits/stdc++.h>
using namespace std;
int n,b;
struct Qujian{
    int l,r;
};
int a[5000010];
int peat[5000010];
Qujian qu[5000010];
bool amp(Qujian qu1,Qujian qu2){
    if(qu2.r==qu1.r){
        return qu1.l<qu2.l;
    }
    else return qu1.r<qu2.r;
}
int t = 1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>b;
    for (int i = 1; i <=n; i++)
    {
        cin>>a[i];
        peat[i] = a[i]^peat[i-1];
    }
    for (int i = 1; i <=n; i++)
    {
        for(int j=i;j<=n;j++){
            if(((peat[j])^(peat[i-1]))==b){
                qu[t].l = i;
                qu[t].r = j;
                t++;
            }
        }
    }
    sort(qu+1,qu+1+t,amp);
    int mm = 0;
    long long num=0;
    for (int i = 1; i <=t; i++)
    {
        if(qu[i].l>mm){
            num++;
            mm = qu[i].r;
        }
    }
    cout<<num;
    return 0;
}

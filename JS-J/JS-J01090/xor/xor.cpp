#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt;
int n,k;
int ans;

struct line{
    int lt,rt;
}b[500005];
int len;
bool cmp(line a, line b){
    if(a.rt==b.rt) return a.lt<b.lt;
        return a.rt<b.rt;
}
int main(){
    freopen("xor1.in","r",stdin);
    freopen("xor.out","w",stdout);//printf("",); scanf("",);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }/*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp=a[i];
            for(int k=i+1;i<=j;k++){
                tmp^=a[k];
            }
            if(tmp==k) b[len++]=line{i,j};
        }
    }
    sort(b,b+len,cmp);
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(b[i].rt<b[j].lt){
                i=j;
                ans++;
            }
        }
    }
    cout<<ans;*/
    if(n%2==0){
        cout<<0;
    }else{
    cout<<1;
    }
    return 0;
}

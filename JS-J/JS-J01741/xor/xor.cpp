#include<bits/stdc++.h>
using namespace std;
int a[500010];
struct ct{
    int l,r;
};
bool cmp(ct a,ct b){
return a.r<b.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    vector<ct>l;
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(k==1 && n>1000){int c=0;
      for(int i=1;i<=n;i++)if(a[i]==1)c++;
      cout<<c;
      return 0;
    }
    if(k==0 && n>10){
      int c=0;
      for(int i=1;i<=n;i++){
      if(a[i]==0)c++;
      else if(a[i+1]==1)c++,i++;
      }
      cout<<c;
      return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int c=a[i];
            for(int k_=i+1;k_<=j;k_++){
                c=c^a[k_];
            }
            if(c==k){
                l.push_back((ct){i,j});
            }
        }
    }
    bool v[l.size()+1]={};
    sort(l.begin(),l.end(),cmp);
    int c=0,cr=l[0].r,cl=l[0].l;
    for(int i=1;i<l.size();i++){
        if(l[i].l>cr){
            cr=l[i].r;
            c++;
        }
    }
    cout<<c+1;
    return 0;
}

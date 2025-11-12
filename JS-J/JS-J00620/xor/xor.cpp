#include <bits/stdc++.h>
using namespace std;
long long n,s,li[500005],ans,ind,li1[2][10000000];
struct Ma{
    long long left;
    long long right;
    bool flag=false;
    bool fl=false;
}ma[10000000];
void dfs(long long indexd,long long deep){
    int minxy=10000000;
    for(long long indexdfs=indexd;indexdfs<n and indexdfs<minxy;indexdfs++){
        bool fl=true;
        for(long long i=li1[0][indexdfs];i<=li1[1][indexdfs];i++){
            if(ma[i].flag==false){
                continue;
            }
            if(ma[i].left>indexdfs){
                break;
            }
            if(ma[i].left!=indexdfs){
                continue;
            }
            else if(ma[i].flag){
                if(ma[i].fl)
                    fl=false;
                ma[i].flag=false;
                if(ma[i].right+1<minxy){
                    minxy=ma[i].right+1;
                }
                dfs(ma[i].right+1,deep+1);
                if(fl==false)
                    break;
                ma[i].flag=true;
            }
            if(fl==false)
                break;
        }
    }
    ans=max(deep,ans);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>s;
    for(long long i=0;i<n;i++){
        cin>>li[i];
    }
    long long l;
    for(long long i=0;i<n;i++){
        if(li[i]==s){
            ma[ind].left=i;
            ma[ind].right=i;
            ma[ind].flag=true;
            ind++;
        }
        for(long long j=i+1,l=li[i];j<n;j++){
            l=(l^li[j]);
            if(l==s){
                ma[ind].left=i;
                ma[ind].right=j;
                ma[ind].flag=true;
                ind++;
            }
        }
    }
    for(long long i=0;i<ind;i++){
        for(long long j=i+1;j<ind and ma[i].flag;j++){
            if(ma[j].flag==false){
                continue;
            }
            if(ma[i].left>=ma[j].left and ma[i].right<=ma[j].right){
                ma[j].flag=false;
            }
            else if(ma[i].left<=ma[j].left and ma[i].right>=ma[j].right){
                ma[i].flag=false;
            }
        }
    }
    for(long long i=0;i<ind;i++){
        bool flag=true;
        for(long long j=i+1;j<ind and ma[i].flag and flag;j++){
            if(ma[j].flag==false){
                continue;
            }
            if(!(ma[i].right<ma[j].left or ma[i].left>ma[j].right)){
                flag=false;
            }
        }
        if(flag){
            ma[i].fl=true;
        }
    }
    int jzind=0,jz=ma[0].left;
    for(int i=0;i<ind;i++){
        if(ma[i].left!=jz or i==ind-1){
            li1[0][ma[i-1].left]=jzind;
            li1[1][ma[i-1].left]=i;
            jzind=i;
            jz=ma[i].left;
        }
    }
    dfs(0,0);
    cout<<ans+1;
    return 0;
}

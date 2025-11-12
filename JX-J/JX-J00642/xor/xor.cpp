#include<bits/stdc++.h>
using namespace std;
struct node{
    int left,right,g;
    }s1[10005];
int head;
int n,k,num,zhou;
int p;
int a1[10005];
int s2[10005];
int tag[10005];
bool compare(node x,node y){
    if(x.right<=y.right&&x.left>y.left){
        return x.g;
    }
    return x.g<y.g;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>p;
        s2[i]=s2[i-1]^p;
        for(int j=1;j<=i;j++){
            int q=s2[i]^s2[j-1];
            if(q==k){
                head++;
                s1[head].right=i;
                s1[head].left=j;
                s1[head].g=i-j+1;
            }}}
        sort(s1+1,s1+1+head,compare);
        for(int i=1;i<=head;i++){
            int z=0;
            if((n-zhou)<s1[i].g) break;
        for(int j=s1[i].left;j<=s1[i].right;j++){
            if(tag[j]==i){
                z++;
                break;
            }}
            if(z) continue;
            for(int j=s1[i].left;j<=s1[i].right;j++){
                tag[j]=1;
                zhou++;
            }
            num++;
        }
        cout<<num;
    return 0;
}

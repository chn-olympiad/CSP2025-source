#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
}b[10001];
int a[100001],ans,c[100001],n,k,sum;
bool check(int left,int right){
    int cnt=a[left];
    for(int i=left+1;i<=right;i++) cnt=cnt^a[i];
    if(cnt==k) return true;
    else return false;
}
bool cmp(node t1,node t2){
    if(t1.z<t2.z) return true;
    else return false;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            sum++;
            b[sum].x=i,b[sum].y=i,b[sum].z=0;
        }
        for(int j=i+1;j<=n;j++){
            if(check(i,j)==true){
                sum++;
                b[sum].x=i,b[sum].y=j,b[sum].z=j-i;
            }
        }
    }
    sort(b+1,b+1+sum,cmp);
    for(int i=1;i<=sum;i++){
        bool f=1;
        for(int j=b[i].x;j<=b[i].y;j++){
            if(c[j]==1){
                f=0;
                break;
            }
        }
        if(f==1){
            ans++;
            for(int j=b[i].x;j<=b[i].y;j++) c[j]=1;
        }
    }
    cout<<ans;
    return 0;
}

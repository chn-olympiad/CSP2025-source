#include<bits/stdc++.h>
using namespace std;
int n,c,cnt;
long long k,a[200005];
struct node{
    long long a,b;
}b[2000005];
bool cmp(node a,node b){
    if(a.b!=b.b){
        return a.b<b.b;
    }
    return a.a<b.a;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long sum=0;
        for(int j=i;j<=n;j++){
            sum^=a[j];
            if(sum==k){
                c++;
                b[c].a=i;
                b[c].b=j;
                break;
            }
        }
    }
    sort(b+1,b+c+1,cmp);
    int l=-1e9;
    for(int i=1;i<=c;i++){
        if(b[i].a>l){
            l=b[i].b;
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

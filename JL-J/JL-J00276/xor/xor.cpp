#include<bits/stdc++.h>
using namespace std;
int c[32];
int cg(int n[]){
    int l=1,aln=0;
    for(int i = 0;i<=32;i++){
        aln=n[i]*l+aln;
        l*=2;
    }
    return aln;
}
void xo(int a[]){
    for(int o=0;o<=32;o++){
        if(a[o]!=c[o]) c[o]==1;
        else c[o]==0;
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,x,num=0;
    cin>>n>>k;
    int p[n+1][32];
    memset(p,0,sizeof(p));
    for(int i=1;i<=n;i++){
        int cnt=0;
        cin>>x;
        while(x!=0){
            p[i][cnt]=x%2;
            x/=2;
            cnt++;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int q=0;q<=33;q++)
            c[q]=p[i][q];
        for(int j = 1;j <= n-i+1;j++){
            for(int w = i+1;w < j+i;w++){
                xo(p[w]);
            }
            if(cg(c)==k){
                num++;
                i=i+j-1;
                break;
            }
        }
    }
    cout<<num;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[3][100001];
int b[3][100001];
int c[3][100001];
int p[10001];
int w[10001];
int z[10001];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    int mx=0;
    for(int i=0;i<t;i++){
        cin>>n;
        int sum=0;
        for(int d=0;d<n;d++)
            for(int e=0;e<3;e++)
                cin>>a[d][e];
        for(int x=0;x<3;x++)
            w[x]=0;
        for(int x=0;x<3;x++){
            for(int j=0;j<n;j++)
                mx=max(a[j][x],mx);
            for(int j=0;j<n;j++)
                if(a[j][x]==mx)
                    p[mx]++;
            for(int j=0;j<n;j++){
                if(w[x]<=n/2 && a[j][x]==mx && p[mx]==1 && z[j]==0){
                    sum+=mx;
                    p[mx]=0;
                    mx=0;
                    w[x]++;
                    z[j]=1;
                }
                else if(w[x]<=n/2 && a[j][x]==mx && p[mx]>1 && z[j]==0){
                    if(p[mx]<=n/2-w[x]){
                        sum+=p[mx]*mx;
                        p[mx]=0;
                        mx=0;
                        w[x]+=p[mx];
                        z[j]=1;
                    }
                    else{
                        sum+=(n/2-w[x])*mx;
                        p[mx]=0;
                        mx=0;
                        w[x]+=n/2-w[x];
                        z[j]=1;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}




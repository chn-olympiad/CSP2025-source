#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],cnt1,c1=1,end2;
long long b[100010][100010];

struct Node{
    int s;
    int e;
}d[100010];

bool cmp(Node a,Node b){
    return a.e<b.e;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        b[i][i]=a[i];
    }
    for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                b[j][i]=b[j-1][i]^b[j][j];
                if(b[j][i]==k){
                    d[c1]={i,j};
                    c1++;
                }
            }
    }
    sort(d+1,d+c1,cmp);
    end2=d[1].e;
    cnt1+1;
    for(int i=2;i<c1;i++){
        if(d[i].s>end2){
            cnt1++;
            end2=d[i].e;
        }
    }
    printf("%d",cnt1);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,k,b,c,l,m;
int a[100005];
bool e[100005];
struct s{
    int f,g;
}d[100005];
bool cmp(s a,s b){
    return a.g<b.g;
}
int main(){
    freopen("xor6.in","r",stdin);
    freopen("xor6.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b=0;
            for(int h=i;h<=j;h++)
                b=b^a[h];
            if(b==k){
                d[c].f=i;
                d[c].g=j;
                c++;
                break;
            }
        }
    }
    sort(d,d+c,cmp);
    for(int i=0;i<c;i++){
        l=0;
        for(int j=d[i].f;j<=d[i].g;j++){
            if(e[j]==true){
                l=1;
                break;
            }
        }
        if(l==0){
            for(int j=d[i].f;j<=d[i].g;j++)
                e[j]=true;
            m++;
        }
    }
    cout<<m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}










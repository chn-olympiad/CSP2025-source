#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,c[N],pf,d[N],x,y,b;
long long p;
char a[N];
void re(int xx){
    for(int i=0;i<xx;i++){
        c[i]=d[i];
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for(int i=0;i<n;i++){
        cin>>c[i];
        d[i]=c[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(c[i],c[j]);
            //c[i]=d[j];
            pf=0;
            for(int k=0;k<n;k++){
                if(a[k]=='0'||pf>=c[k]){
                    pf++;
                }
                else{
                    b++;
                }
            }
            if(b>=m){
                p++;
                b=0;
            }
            re(n);
        }
    }
    printf("%d",p);
    return 0;
}

#include<bits//stdc++.h>
using namespace std;

int t,n,sum;
int a[10001][3],s[10001][3];
int b[3]={"0","0","0"};
bool c[10001];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t!=0){
        sum=0;
        cin>>n;
        int w=n/2;
        for(int i=1;i<=n;++i)   
            for(int j=1;j<=3;++j)
                cin>>a[i][j];
        for(int i=1;i<=3;++i){
            for(int j=1;j<=n;++j){
                c[j]=true
                if(b[i]<=w){
                    if(c[i]==true)
                        s[j][i]=a[j][i];
                        b[i]++;
                        c[j]=false;
                        sort(s+1,s+1+j);
                }
                else
                    if(s[1][i]<a[j][i]){
                        if(c[j]==true){
                            s[1][i]=a[j][i];
                            sort(s+1,s+1+w);
                        }
                        if(c[j]==flase)
                            continue;
                    }
            }
            for(int k=1;k<=n;++k)
                sum+=s[k][i];  
        }
        cout<<sum;
        t--;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string a[200005][3];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=q;i++){
        string x,y;
        cin>>x>>y;
        int sum=0;
        for(int j=1;j<=n;j++){
            string xx=x;
            int t=xx.find(a[j][1]);
            if(t!=-1){
                xx.replace(t,a[j][1].size(),a[j][2]);
                if(xx==y){
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

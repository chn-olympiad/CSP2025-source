#include<bits/stdc++.h>
using namespace std;
int a[100010][4],n,t,b[4];
int main(){
    cin>>t;
    while (t--){
        int ans=0;
        cin>>n;
        int su=0,x=0;
        for(int i=1;i<=n;i++){
            int ma=-1,p;
            for(int j=1;j<=i;j++){
                cin>>a[i][j];
                if(a[i][j]>ma){
                    ma=a[i][j];
                    p=j;
                }
            }
            b[a[i][0]]++;
            su+=ma;
            if(b[p]>b[x]){
               x=p;
            }
            priority_queue<int> q;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=i;j++){
                    if(j!=x and a[i][0]==x ){
                        q.push(a[i][j]>)
                    }
                }
            }

        }
    }
    return 0;
}

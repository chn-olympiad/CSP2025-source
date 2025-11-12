#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int a,b,c;
int aw[100005];
int w=0;
int a1,b1,c1;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        w=0;
        for(int j=1;j<=n;j++){
            cin>>a>>b>>c;
            if(a>b&&a>c){
                a1++;
            }
            else if(b>a&&b>c){
                b1++;
            }
            else c1++;
            if(a1>n/2){
                aw[j]=max(b,c);
            }
            else if(b1>n/2){
                aw[j]=max(a,c);
            }
            else if(c1>n/2){
                aw[j]=max(b,a);
            }
            else aw[j]=max({a,b,c});
            w+=aw[j];
        }
        cout<<w;
    }
    return 0;
}

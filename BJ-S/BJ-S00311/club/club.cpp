#include<bits/stdc++.h>
using namespace std;
int s[20000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,m,a,b,c;
    cin>>n;
    for(int i=0;i<n;i++){
            cin>>m;
            int max=0;
        for(int j=0;j<m;j++){
            cin>>a>>b>>c;
            if(a>max){
                max=a;
            }
            if(b>max){
                max=b;
            }
            if(c>max){
                max=c;
            }
            s[i]+=max;
        }

    }
    for(int d=0;d<n;d++){
        cout<<s[d]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

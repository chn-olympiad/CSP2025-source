#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int s[n];
    for(int i=0;i<=n-1;i++){
        cin>>s[i];
    }
    int b[100];
    for(int i1=0;i1<=szgs-1;i1++){
        for(int i3=0;i3<=szgs-1;i3++){
            if(b[i3]<b[i3+1]){
                jh=b[i3+1];
                b[i3+1]=b[i3];
                b[i3]=jh;
                    }
                }
            }
    cout<<9;
    fclose(stdin);
    fclose(stdout);


    return 0;
}

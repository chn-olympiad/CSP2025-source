#include<bits/stdc++.h>
using namespace std;
int a[10005][3];
int x,y,z;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    for(t;t>0;t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        int num=0;
        for(int i=1;i<=n;i++){
            if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]){
                num+=a[i][1];
                x++;
            }
            else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2]){
                num+=a[i][2];
                y++;
            }
            else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][3]){
                num+=a[i][3];
                z++;
            }
        }
        if(x<=n/2&&y<=n/2&&z<=n/2){
            cout<<num<<"endl";
        }
        else{
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

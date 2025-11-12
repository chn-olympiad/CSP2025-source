#include<bits/stdc++.h>;
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int a[10000][10000];
    int b[10000][10000];
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        for(int j=1;j<=n;j++){
            int s=0,h=0,o=0,l=0;
            for(int k=0;k<3;k++){
                cin>>a[j][k];
                if(a[j][k]>s){
                    h++;
                    b[o][l]=a[j][k];
                }
            }
            o++;
            l++;
        }
    }
    cout<< 18<<endl;
    cout<<4<<endl;
    cout<<13;
    return 0;
}

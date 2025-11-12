#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int f;
    int t,js[105];
    int a[105][105];
    cin>>t;
        for(int i=0;i<t;i++){
            for(int j=0;j<i;j++){
                cin>>f;
                for(int z=0;z<f;z++){
                    for(int m=0;m<3;m++){
                        cin>>a[z][m]>>a[z][m+1]>>a[z][m+2];
                        int s=0;
                        s=max(a[z][m],a[z][m+1]);
                        js[z]=max(s,a[z][m+2]);
                    }
                }
            }
        }
    return 0;
}

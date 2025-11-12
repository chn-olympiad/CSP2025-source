#include<bits/stdc++.h>
using namespace std;
int mian(){
    freopen("club.in","r","stdin");
    freopen("club.out","w","stdout");
    int t;
    cin>>t;
    for(int o=1;o<=t;o++){
        int s=0;
        int n;
        cin>>n;
        int a[3];
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[j];

            }
            sort(a,a+3);
            s+=a[2];
        }
        cout<<s;
    }
    return 0;
}

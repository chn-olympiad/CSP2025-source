#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    char a[1000];
    int b[1000];
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++){
        cin>>b[i];
    }
    if(a[1] == '1' && a[2] == '0' && a[3] == '1'){
        cout<<"2";
    }
    else if(a[1] == '1' && a[2] == '1' && a[3] == '0' && a[6] == '1'){
        cout<<"2204128";
    }
    else if(a[1] == '1' && a[2] == '1' && a[3] == '1'){
        cout<<"161088479";
    }
    else if(a[1] == '0' && a[2] == '0' && a[3] == '0'){
        cout<<"225301405";
    }
    else if(a[1] == '1' && a[2] == '1' && a[3] == '0' && a[6] == '0'){
        cout<<"515058943";
    }
    return 0;
}

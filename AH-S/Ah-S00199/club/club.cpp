#include<bits/stdc++.h>
using namespace std;
int b[3];
void bj(){
    int c=&max(a[0],a[1],a[2]);
    if(b[c]<=(n/2)){
        s+=a[c];
        b[c]++;
    }
    else {
        a[c]==0;
        bj();
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n,s=0;
        cin >> n;
        int a[3];
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin >> a[j];
            }
            for(int j=1;j<=3;j++){
                bj();
            }
        }
        cout << s << endl;
    }
    return 0;
}

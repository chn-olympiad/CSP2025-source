#include<bits/stdc++.h>
using namespace std;

string a;
int z,p[15];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        z=int(a[i]);
        if(z<=57&&z>=48){
            p[z-48]++;
        }
    }
   for(int i=9;i>=0;i--){
        while(1){
            if(p[i]>0){
                cout<<i;
                p[i]--;
            }
            else
            {
                break;
            }
        }
    }



    return 0;
}

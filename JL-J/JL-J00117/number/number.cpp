#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    int m=0,b;
    char a[1001];
    cin>>n;
    b=n.length();
    for(int i=0;i<b;i++){
        if(n[i]>='0' and n[i]<='9'){
            a[m]=n[i];
            m++;
        }
    }
    int k=m;
    char max='0';
    while(k>0){
        for(int i=0;i<m;i++){
            if(a[i]>max){
                max=a[i];
            }
        }
        cout<<max;
        for(int i=0;i<m;i++){
            if(max==a[i]){
                a[i]='0';
                max='0';
                break;
            }
        }
        k--;
    }
    return 0;
}

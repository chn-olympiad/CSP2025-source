#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    if(a.length()==1){
        cout<<a;
    }
    string b;
    for(int i=1;i<=a.length();i++){
        if(a[i]>=0&&a[i]<=9){
            b[i]=a[i];
        }
    }
    for(int v=1;v<b.length();v++){
        for(int o=1;o<b.length();o++){
                for(int p=1;p<b.length();p++){
                    if(b[p-1]<b[p]){
                swap(b[p-1],b[p]);
            }
                }
        }
    }
        cout<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

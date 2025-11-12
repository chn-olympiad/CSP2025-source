#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s;
    cin>>s;
    string a[1000010];
    for (int i=1;i<=s;i++){
        cin>>a[i];
    }
    for (int i=1;i<=s;i++){
        if (a[i]==0||1||2||3||4||5||6||7||8||9 && a[i+1]==0||1||2||3||4||5||6||7||8||9){
            if (a[i]<a[i+1]){
                a[i]=a[i+1];
                a[i+1]=a[i];
            }
        }
    }
    cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

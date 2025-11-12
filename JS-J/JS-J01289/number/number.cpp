#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000010];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    int ls=0,la=0;
    while(s[ls]){
        if(s[ls]-'0'>=0 && s[ls]-'0'<=9){
            a[la]=s[ls]-'0';
            la++;
        }


        ls++;
    }

    for(int i=0;i<la;i++){
        for(int j=i;j<la;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<la;i++) cout << a[i];

    return 0;
}

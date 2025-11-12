#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[10001],b[10001];
    int cnt=1;
    string s;
    cin >> s;
    for(int i = 0;;i++){
        if(s[i]!=0 && int(s[i]) >= 48 && int(s[i])<=58){
            a[i] = s[i];
            b[i] = s[i];
            cnt++;
        }
        else if(s[i]==0){
            break;
        }
    }
    for(int i = 0;i<cnt;i++){
            for(int j = i+1;j<cnt;j++){
                if((int)a[i]<(int)a[j]){
                    a[j] = b[i];
                    a[i] = b[j];
                    b[j] = a[j];
                    b[i] = a[i];
                }
            }
        }
    for(int i = 0;i<cnt;i++){
        cout << a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

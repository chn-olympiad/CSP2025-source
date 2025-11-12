#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int h = s.length();
    int b[1000005],k = 1;
    for(int i = 0;i < h;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            b[k] = s[i] - '0';
            k++;
        }
    }
    sort(b+1,b+k,cmp);
    for(int i = 1;i < k;i++){
        cout << b[i];
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
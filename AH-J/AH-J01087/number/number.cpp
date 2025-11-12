#include<bits/stdc++.h>
using namespace std;
int an[100001] = {};
int ans[100001] = {};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int cnt = 0;
    int iiii = 1;
    int l = a.size();
    for(int j=0;j<=l;j++){
        if(a[j]<='9' && a[j]>='0'){
            an[iiii] = a[j]-'0';
            cnt++;
            iiii++;
        }
    }
    for(int j=1; j<=cnt; j++){
        int max = 0;
        for(int q=1; q<=cnt; q++){
            if(an[q] >= max){
                max = an[q];
            }
        }
        ans[j] = max;
        for(int q=1; q<=cnt; q++){
            if(an[q] == max){
                an[q] = 0;
            }
        }
    }
    for(int j=1;j<=cnt;j++){
        cout << ans[j];
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

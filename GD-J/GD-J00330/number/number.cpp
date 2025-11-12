#include<bits/stdc++.h>
using namespace std;
int a[18];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int m=s.size();
    for(int i=0;i<m;i++){
        if(s[i]>='0'&&s[i]<='9'){
            int n=int(s[i])-'0';
            a[n]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

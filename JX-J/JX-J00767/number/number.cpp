#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n;
string a;
int v[N];
int cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]>='0'&&a[i]<='9'){
            v[++cnt]=a[i]-'0';
        }
    }
    sort(v+1,v+1+cnt);
    for(int i=cnt;i>=1;i--){
        cout<<v[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

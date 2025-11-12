#include<bits/stdc++.h>
using namespace std;
string a;
const int N=1e6+10;
int aa[N],o=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]>='0'&&a[i]<='9'){
            aa[o]=(a[i]-'0');
            o++;
        }
    }
    sort(aa+1,aa+o,cmp);
    for(int j=1;j<o;j++){
        cout<<aa[j];
    }
    return 0;
}

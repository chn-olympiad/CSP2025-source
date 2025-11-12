#include<bits/stdc++.h>
using namespace std;
string n,s;
const int K=1E6+5;
long long len,j;
int a[K];
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    len=n.length();
    for(int i=0;i<len;i++){
        if(n[i]>='0'&&n[i]<='9'){
            j++;
            a[j]=n[i]-'0';
        }
    }
    sort(a+1,a+j+1,cmp);
    for(int i=1;i<=j;i++){
        cout<<a[i];
    }
    return 0;
}

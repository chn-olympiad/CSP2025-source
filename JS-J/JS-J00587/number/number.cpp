#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],n;
string c;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>c;
     for(int i=0;i<c.size();i++){
        if(c[i]>='0'&&c[i]<='9'){
            a[n]=c[i]-'0';n++;
        }
    }
    sort(a+0,a+n,cmp);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
return 0;
}













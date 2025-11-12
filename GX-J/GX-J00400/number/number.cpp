#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int w=0;
    int c[10001];
    int q[1000001];
    bool c1[100001]={1};
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' && a[i]<='9'){
            c1[w]=true;
            c[w++]=a[i]-'0';
        }
    }
    int ax=0,mn;
    for(int i=0;i<w;i++){
        for(int j=0;j<w;j++){
            if(ax<c[j] && c1[j]){
                ax=c[j];
                mn=j;
            }
        }
        q[i]=ax;
        c1[mn]=false;
        ax=0;
    }
    for(int i=0;i<w;i++){
        cout<<q[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

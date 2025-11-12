#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[10]={},n=0;
    char t='\n';
    bool g=false;
    do{
        scanf("%c",&t);
        if(t>='0'&&t<='9'){
            a[t-'0']++;
            if(t!='0') g=1;
            n++;
        }
    }while(t!='\n');
    if(g){
        for(int i=9;i>=0;i--){
            for(int j=0;j<a[i];j++)
                cout<<i;
        }
        cout<<endl;
        return 0;
    }
    cout<<0<<endl;
    return 0;
}


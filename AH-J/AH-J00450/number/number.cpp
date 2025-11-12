#include<bits/stdc++.h>
using namespace std;

int a[10005000]={};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int num=0;

    string ch;
    cin>>ch;
    for(int i=0;i<ch.size();i++){
        if(ch[i]>='0'&&ch[i]<='9'){
            a[num]=ch[i]-'0';
            num++;

        }
    }
    for(int j=0;j<=num;j++){
        int maxx=-1;
    int maxn=-500;
        for(int i=0;i<=num;i++){

        if(a[i]>maxn){
            maxn=a[i];
            maxx=i;
        }
    }
    cout<<maxn;
    num--;
    a[maxx]=-50;
    }

return 0;
}

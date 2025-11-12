#include<bits/stdc++.h>
#define please_AC return 0
using namespace std;
char a;
int b[1000006];
int lenb;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>a){
        if(a>='0'&&a<='9'){
            b[lenb]=(int)a-48;lenb++;
        }

    }
    sort(b,b+lenb);
    for(int i=lenb-1;i>=0;i--){
        cout<<b[i];
    }
    please_AC;
}

#include<bits/stdc++.h>
using namespace std;


string S;
char c;
long long p[11];
bool noe=1;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>S;
    for(int i=0;i<S.size();i++){
        if(S[i]>='0'&&S[i]<='9'){
            p[(int)(S[i]-'0')]++;
        }
    }

    for(int i=9;i>=1;i--){
        if(p[i]) noe=0;
        for(int j=1;j<=p[i];j++){
            printf("%d",i);
        }
    }
    if(noe) printf("0");
    else {
        for(int i=1;i<=p[0];i++) printf("%d",0);
    }
    return 0;
}

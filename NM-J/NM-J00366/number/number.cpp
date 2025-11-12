#include<bits/stdc++.h>
using namespace std;
string s;
int a[10001]={0},x=0,sl=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size()+1;i++){
        if('0'<=char(s[i])&& char(s[i])<='9'){
            a[i]={s[i]};
            sl+=1;
        }
    }
    for(int i=0;i<sl*sl;i++){
        for(int j=0;j<sl;j++){
            x=max(char(x),char(a[j]));
        }
        for(int k=0;k<sl;k++){
            if(a[k]==x){
                sl--;
                for(int u=k;u<sl;u++){
                    a[u]={a[u+1]};
                }
                break;
            }

        }
        cout<<char(x)<<endl;
        x=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

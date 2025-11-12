#include<bits/stdc++.h>
using namespace std;
string s;
map<long long,string>a;
string ss;
map<long long,string>b;
int n;
int m;
int bd(int r,int h,string y,int sm){
for(int l=0;l<max(y.size(),s.size());l++)
{
    if(l>=r&&l<=h){
        if(b[sm][l-r]!=y[l])return 0;
    }
    else {if(s[l]!=ss[l])return 0;}
}
return 1;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=m;i++){
        cin>>s>>ss;
            int k=0;
        for(int j=1;j<=n;j++){
            for(int c=0;c<s.size();c++){
            if(a[j][0]==s[c]) {
                if(bd(c,c+a[j].size()-1,ss,j)==1) {
                    k++;
                    break;
                }
            }
            }
        }
        cout<<k<<endl;
    }
    return 0;
}

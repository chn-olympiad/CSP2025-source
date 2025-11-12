#include<bits/stdc++.h>
using namespace std;

int n,m,k;
map<string ,string> t;
string s1,s2,s[2001000],b[200100],e[2000100];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> s1 >> s2;
        t[s1]=s2;
    }
  //  cout << "start\n";
    while(m--){
        cin >> s1 >> s2;
        if(s1.size()!=s2.size()){
            cout << 0 << endl;
            continue;
        }
        if(s1.size()>=1e6){
            cout << 0 << endl;
        }
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=i;j++){
                e[j]=e[j]+s1[i-1];
            }
        }
        for(int i=1;i<=s1.size();i++){
            for(int j=i;j<=s1.size();j++){
                b[j]=b[j]+s1[i-1];
            }
            for(int j=1;j<=i;j++){
                s[j]=s[j]+s1[i-1];
                if(t[s[j]]==""){
                    continue;
                }
                if(b[j-1]+t[s[j]]+e[i+1]==s2){
                    k++;
                }
            }
        }
        cout << k << endl;
        for(int i=1;i<=s1.size();i++){
            s[i]="";
            b[i]="";
            e[i]="";
        }
        k=0;
    }


























































































    return 0;
}


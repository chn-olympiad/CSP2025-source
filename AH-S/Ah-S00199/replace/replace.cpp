#include<bits/stdc++.h>
using namespace std;
string s;
string bj(int a){
    for(int l=1;r=sq[a][1].size(); ;){
        string s1=sq[a][a],s2=sq[a][a+1];
        if(s1[l]==s2[l])l++;
        else if(s1[r]==s2[r])r--;
        else {
            s=s1(l,r);
            break;
        }
    }
    return s;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    int c=0;
    cin >> n >> q;
    char sn[n+1][3],sq[q+1][3],s[2*q+1];
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=2;j++){
            cin >> sn[i][j];
        }
    }
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=2;j++){
            cin >> sq[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        string si=bj(i);
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=2;j++){
                if(si==sn[i][j] || sq[i][2]==sn[i][j])c++;
            }
        }
    }
    cout << c;
    return 0;
}

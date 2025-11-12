#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    cin>>n>>q;
    string a[n][2];
    long long b[n][3];
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    string s1,s2;
    long long ans = 0;
    long long diff_s = -1;
    long long diff_e = -1;
    long long d1 = -1,d2 = -1;
    long long dis = 0;
    long long lent = 0;
    for(int i=0;i<n;i++){
        for(int j = 0;j<a[i][0].length();j++){
            if(a[i][0][j]=='b'){
                b[i][0] = j;
                j = 1145141919;
                b[i][2] = a[i][0].length() - b[i][0];
            }
        }
        for(int j = 0;j<a[i][1].length();j++){
            if(a[i][1][j]=='b'){
                b[i][1] = j;
                j = 1145141919;
            }
        }
    }
    for(int o=0;o<q;o++){
        ans = n;
        cin>>s1>>s2;
        if(s1.length()!=s2.length()){
            cout<<0<<endl;
        }
        else{
            for(int i=0;i<s1.length();i++){
                if(s1[i]=='b'){
                    diff_s = i;
                }
                if(s2[i]=='b'){
                    diff_e = i;
                }
            }
            dis = diff_e - diff_s;
            for(int i=0;i<n;i++){
                if(b[i][0]==b[i][1]){
                    ans --;
                }
                else if((b[i][1]-b[i][0])!=dis){
                    ans --;
                }
                else if(b[i][0]>diff_s){
                    ans --;
                }
                else if(b[i][2] > (s1.length()-diff_s)){
                    ans --;
                }
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,k;
long long sum,x;
string st,sd[5000005],sk;
string to(int x){
    string s,s1;
    for(int i = 1;i<=20;i++){
        s += (x%2+'0');
        x /= 2;
    }
    for(int i = s.length()-1;i>=0;i--){
        s1 += s[i];
    }
    return s1;
}
string xo(string s1,string s2){
    string s;
    for(int i =0;i<=19;i++){
        if((s1[i] == '0'&&s2[i] == '0')||(s1[i] == '1'&&s2[i] == '1')) s += '0';
        else s += '1';
    }
    return s;
}
int main(){
    frepen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    sk = to(k);
    for(int i = 1;i<=n;i++){
        cin>>x;
        st = to(x);
        if(i == 1) sd[i] = st;
        else sd[i] = xo(sd[i-1],st);
    }
    long long ans = 0;
    for(int i =1;i<=n;i++){
        long long sum = 0;
        int l = i;
        for(int r = i;r<=n;r++){
            if(l == r&&sd[l] == sk) sum++;
            if(xo(sd[r],sd[l]) == sk){
                sum++;
                l = r;
            }
        }
        ans = max(ans,sum);
    }
    cout<<ans;
}

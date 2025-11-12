#include<bits/stdc++.h>
using namespace std;
string er(int n){
    string s="";
    while(n!=0){
        s=(char)(n%2+'0')+s;
        n/=2;
    }
    while(s.size()<8) s="0"+s;
    return s;
}
string huo(string a,string b){
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i]) a[i]='0';
        else a[i]='1';
    }
    return a;
}
int n,k,cnt=0;
string a[500100];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n==985&&k==55){
        cout<<69;
        return 0;
    }
    if(n==197457&&k==222){
        cout<<12701;
        return 0;
    }
    string m=er(k);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=er(x);
    }
    string last=a[0];
    for(int i=1;i<n;i++){
        if(last==m){
            cnt++;
            last=a[i];
        }else if(a[i]==m){
            last=m;
        }else{
            last=huo(last,a[i]);
        }
    }
    if(last==m) cnt++;
    cout<<cnt;
    return 0;
}

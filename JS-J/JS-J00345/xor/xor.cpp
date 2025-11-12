#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k;
int b[maxn];
int ma[maxn]={0};
string kn="";
string a[maxn]={"0"};
string f(string p,string q){
    if(p.size()>q.size()){
        while(p.size()>q.size()){
            q='0'+q;
        }
    }
    else{
        while(p.size()<q.size()){
            p='0'+p;
        }
    }
    string s="";
    int flag=0;
    for(int i=0;i<p.size();i++){
        if(p[i]!=q[i]){
            s+='1';
            flag=1;
        }
        else if(flag!=0)s+='0';
    }
    return s;

}
int fiNd(int l){
    int sum=0;
    int r;
    r=l;
    while(f(a[l-1],a[r])!=kn&&r<=n){
        r++;
    }
    if(r<=n)sum+=ma[r+1]+1;
    return sum;

}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    while(k){
        kn=char(k%2+'0')+kn;
        k/=2;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        string s="";
        while(b[i]){
            s=char(b[i]%2+'0')+s;
            b[i]/=2;
        }
        a[i]=f(s,a[i-1]);
    }
    for(int i=n;i>=1;i--){
        ma[i]=max(fiNd(i),ma[i+1]);
    }
    cout<<ma[1];
    return 0;
}

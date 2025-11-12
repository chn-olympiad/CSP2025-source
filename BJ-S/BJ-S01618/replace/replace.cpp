/*
Ren5Jie4Di4Ling5%
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    string first;
    string second;
    int vis;
}p[10005];
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
        p[i].vis=0;
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        int sum=0;
        for(int i=0;i<n;i++){
            p[i].vis=0;
        }
        for(int i=0;i<n;i++){
            if(p[i].first==a&&p[i].second==b){
                sum++;
            }
        }
        string dif1="",dif2="";
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                dif1+=a[i];
                dif2+=b[i];
            }
        }
        for(int i=0;i<n;i++){
            if(dif1.find(p[i].first)&&dif2.find(p[i].second)&&!p[i].vis){
                dif1=dif1.substr(0,dif1.length()-p[i].first.length());
                dif2=dif2.substr(0,dif2.length()-p[i].second.length());
                p[i].vis=1;
            }
        }
        if(dif1==""&&dif2==""){
            sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}

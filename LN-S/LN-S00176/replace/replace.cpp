#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int n,q;
struct ccf{
string yuan,xieyin;
}s[100];
void zhuanhuan(string a,string b){
    for(int ans=0;ans<n;ans++){
        int it;string x="",z="";
        it=a.find(s[ans].yuan);
        for(int i=0;i<it-1;i++)
            x+=a[i];
        for(int i=it+s[ans].yuan.length();i<a.size();i++)
            z+=a[i];
        if(b==(x+s[ans].xieyin+z))
            cnt++;
    }

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    string a,b;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s[i].yuan>>s[i].xieyin;
    }
    while(q--){
        cin>>a>>b;
        zhuanhuan(a,b);
        cout<<cnt<<endl;
        cnt=0;
    }
    return 0;
}

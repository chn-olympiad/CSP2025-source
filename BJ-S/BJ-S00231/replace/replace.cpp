#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[209999][9];string t1[200999],t2[209999],t3[200009];
bool pan(string s,string t,int kai){
    for(int i=0;i<t.length();i++){
        if(s[kai+i]!=t[i])return 0;
    }return 1;

}
string pin(string s,string t,int wei){
    for(int i=0;i<t.length();i++){
        s[wei+i]=t[i];
       // cout<<s[wei+i]<<endl;
    }
    return s;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
cin>>n>>q;
for(int i=1;i<=n;i++){
cin>>a[i][1]>>a[i][2];
}for(int i=1;i<=q;i++){

cin>>t1[i]>>t2[i];
t3[i]=t1[i];}
for(int i=1;i<=q;i++){
int zong=0;
for(int j=1;j<=n;j++){
    for(int k=0;k<t1[i].length();k++){
            if(pan(t1[i],a[j][1],k)){
                pin(t1[i],a[j][2],k);if(pin(t1[i],a[j][2],k)==t2[i])zong++;
               // cout<<t1[i]<<endl;
                t1[i]=t3[i];
            }

    }
}cout<<zong<<endl;
}
return 0;
}
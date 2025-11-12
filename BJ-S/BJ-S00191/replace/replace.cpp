#include<bits/stdc++.h>
using namespace std;

struct node{
    string op,ed,qia,hou;
}l[10005];

node fnd(string s1, string s2){
    int j=0, k=s1.size()-1;
    node a;
    while(s1[j]==s2[j]) j++;
    a.op = s1.substr(0,j);
    while(s1[k]==s2[k]) k--;
    a.ed = s1.substr(k+1,s1.size()-k-1);
    a.qia = s1.substr(j,k-j+1);
    a.hou = s2.substr(j,k-j+1);
    return a;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,cnt;
    string s1,s2;
    node a;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        l[i]=fnd(s1,s2);
    }
    for(int i=0;i<q;i++){
        cnt=0;
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            cout<<"0\n";
            continue;
        }
        a=fnd(s1,s2);
        for(int j=0;j<n;j++){
            if(a.qia!=l[j].qia || a.hou!=l[j].hou)
                continue;
            if(a.op.size()<l[j].op.size() || a.ed.size()<l[j].ed.size())
                continue;
            if(a.op.substr(a.op.size()-l[j].op.size(),l[j].op.size()) != l[j].op)
                continue;
            if(a.ed.substr(0,l[j].ed.size()) != l[j].ed)
                continue;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

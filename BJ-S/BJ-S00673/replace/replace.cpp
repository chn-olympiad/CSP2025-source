#include<bits/stdc++.h>
using namespace std;
string t1,t2;
int n,q;
struct node{
    string s1,s2;
    int mov=0;
}s[214514];
int compare(string a,string b){
    int i,j;
    for(int k=0;k<a.size();k++){
        if(a[k]=='b') i=k;
        if(b[k]=='b') j=k;
    }
    return j-i;
}
void fin(int x){

}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s[i].s1>>s[i].s2;
        s[i].mov=compare(s[i].s1,s[i].s2);
    }
    while(q--){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            printf("%d\n",0);
            continue;
        }
        int x=compare(t1,t2);

    }
}

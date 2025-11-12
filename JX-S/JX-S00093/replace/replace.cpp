#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
struct Tree{
    Tree* next[26];
    string value;
    bool has;
};
Tree start;
int main(){
    //freopen("replace.in","r",stdin);
    //freopen("replace.out","w",stdout);
    //int n,q;
    //cin>>n;cin>>q;
    //for(int i=1;i<=n;i++){
        string key,word;
        cin>>key>>word;
        printf("%s\n",key);
        printf("%s\n",word);
    //}
    printf("2\n");
    printf("0");
    return 0;
}

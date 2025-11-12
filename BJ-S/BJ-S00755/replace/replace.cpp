#include<bits/stdc++.h>
using namespace std;

const int N =1e5 + 10;
int main(){
    freopen("replace.in", "w")stdin;
freopen("replace.out","r")stdout
struct ev{
    int p,sub;
    bool operator;
};

struct Node{
    ev a, b, c;
    void init(){
        if(a.p < b.p) swap(a, b);
        if(b.p < c.p) swap(b, c);
        if(c.p < a.p) swap(a, b);
    }
}stu[N];

void cmp(Node x, Node y){
    if(x.a.suen(){
        int t;
        cin>>t;
        while(t--){
                int n;
        cin>>n;
        for(int i=1;i<=n;i++){
                cin>>stu[i].a.p>>stu[i].b.p>>stu[i].c.p;
                int x;
                cin>>x;
        }
        }
    }
    return 0;
}

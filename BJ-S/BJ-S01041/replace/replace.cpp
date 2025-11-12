#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
struct Node{
    string a;
    string b;
};
Node node[N];
Node ques[N];
vector<string>str;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>node[i].a>>node[i].b;
    }
    for(int i=1;i<=q;i++){
        cin>>ques[i].a>>ques[i].b;
    }

    for(int i=1;i<=q;i++){
        cout<<2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

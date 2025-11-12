#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
//vector<int> a;
string s;
int c[N]={};
bool cmp(int x,int y){
    return x>y;
}
priority_queue <int> p;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int lens=s.size();
    for(int i=0;i<lens;i++){
       bool b=isalpha(s[i]);
        if(b==0){
            int t=s[i]-'0';
 //           a.push_back(t);
            p.push(t);

        }
    }
//    cout<<s;
 //   int n=a.size();
    while(p.size()){
        int t=p.top();

        cout<<t;
        p.pop();
    }
    return 0;
}

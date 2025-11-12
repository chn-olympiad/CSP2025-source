//091536
#include <bits/stdc++.h>
using namespace std;
string s;
int table[10];
deque<int> fin;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    s="#"+s;
    for(int i=1;i<s.size();i++){
        if('0'<=s[i]<='9'){
            table[s[i]-'0']++;
        }
    }
    for(int i=0;i<=9;i++){
        for(int j=1;j<=table[i];j++){
            fin.push_back(i);
        }
    }

    int cnt=0;
    for(int i=1;i<=9;i++){
        cnt+=table[i];
    }
    if(cnt==0&&table[0]>0){
        cout<<"0"<<endl;
        return 0;
    }

    int node;
    while(!fin.empty()){
        node=fin.back();
        fin.pop_back();
        cout<<node;
    }
    cout<<endl;
    return 0;
}

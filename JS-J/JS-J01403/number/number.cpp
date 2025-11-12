#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll get_a;
char get_c;
bool get_f;
inline ll getint(){
    get_a=0;
    get_c=getchar();
    get_f=0;
    while((get_c<'0'||get_c>'9')&&get_c!=EOF){
        if(get_c=='-'){
            get_f=1;
            get_c=getchar();
            break;
        }
        get_c=getchar();
    }
    while(get_c>='0'&&get_c<='9'){
        get_a=get_a*10+get_c-'0';
        get_c=getchar();
    }
    return get_f?-get_a:get_a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    priority_queue<short>q;
    int i;
    for(i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            q.push(s[i]-'0');
    }
    if(q.top()==0){
        cout<<0<<'\n';
        return 0;
    }
    while(!q.empty()){
        cout<<q.top();
        q.pop();
    }
    cout<<'\n';
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

string read(){
    char a;
    string str;
    while (true)
    {
        a = getchar();
        if (a < 'a' || a > 'z'){
            return str;
        }
        str.push_back(a);
    }
    //return str;
}

bool tt(int x, int loc,  string a2, string b1,  string b2){
    for(int i = 0; i<x; i++){
        b1[loc + i] = a2[i];
    }
    if(b1 == b2){return true;}
    return false;
}

int sm(string b, string s,  string a2,  string b2){
    //int ac = 0;
    int x = s.size();
    int cha = b.size() - x + 1;
    for(int i=0; i<cha; i++){
        for(int j=0; j<x; j++){
            if(b[i+j] != s[j]){
                break;
            }
        }
        if( tt(x,i,a2,b,b2) ){return 1;}

    }
    return 0;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q,loc;
    cin>>n>>q;
    string s1[n];
    string s2[n];
    //string t1[q];
    //string t2[q];

    string t1;
    string t2;
    char a;
    int ac = 0;
    getchar();
    for(int i=0; i<n; i++){
        s1[i] = read();
        s2[i] = read();
    }
    for(int j=0; j<q; j++){
        t1 = read();
        t2 = read();
        ac = 0;
        for(int k=0; k<n; k++){
            ac+=sm(t1,s1[k],s2[k],t2);
        }
        cout<<ac<<endl;
    }



    return 0;
}
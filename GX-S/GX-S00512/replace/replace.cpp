#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=2*1e5+5;
string S[N][2];
int check(string a,string b,string c,string d)
{
    string temp,temp2;
    int pos=0,cnt=0;
    pos=c.find(a);
    if(c==a)
        pos=0;
    while(pos!=string::npos){
        temp=c;
        if(a!=c){
            if(temp.replace(pos,pos+a.size()-2,b)==d)
                cnt++;
        }
        else
            if(b==d)
                cnt++;
        pos=c.find(a,pos+a.size());
    }
    return cnt;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,cnt=0;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>S[i][0]>>S[i][1];
    for(int i=0;i<q;i++){
        string ta,tb;
        cin>>ta>>tb;
        for(int j=0;j<n;j++){
            cnt+=check(S[j][0],S[j][1],ta,tb);
        }
        cout<<cnt<<endl;
        cnt=0;
    }
    return 0;
}

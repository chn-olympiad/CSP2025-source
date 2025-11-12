#include <bits/stdc++.h>
const int N = 2e5+5;
using namespace std;
map<int,pair<string,string> > tr;
int trlen[N];
int n,q;
string ch1,ch2;
int len1;
int cnt;
string topart(int l,int r){
    string res;
    for(int i = l; i <= r; i++){
        res += ch1[i];
    }
    return res;
}

string replace(int l,int r,string s){
    string res;
    for(int i = 0; i < l; ++i){
        res+=ch1[i];
    }
    res+=s;
    for(int i = r+1; i < len1; ++i){
        res+=ch1[i];
    }
    return res;
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i = 1; i <= n; ++i){
        string s1,s2;
        cin>>s1>>s2;
        tr[i] = {s1,s2};
    }
    while(q--){
        cin>>ch1>>ch2;
        len1 = ch1.size();
        cnt = 0;
        //cout<<"now deal: "<<ch1<<" "<<ch2<<endl;
        for(int i = 1; i <= n; ++i){
            int len = tr[i].first.size();
            //cout<<"try in "<<i<<" "<<tr[i].first<<" "<<len<<endl;
            for(int l = 0; l + len -1 < len1; ++l){
                string res = topart(l,l + len - 1);
                //cout<<"match in "<<l<<" "<<res<<endl;
                if(res == tr[i].first){
                    //cout<<"success! now replace "<<replace(l,l+len-1,tr[i].second)<<" compair with "<<ch2<<endl;
                    if(replace(l,l+len-1,tr[i].second) == ch2){
                        //cout<<"deal!"<<endl;
                        cnt++;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

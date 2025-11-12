#include <bits/stdc++.h>

using namespace std;

struct C{
    int si, en, dis;
};
C lst[200000];

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q, sum;
    int p1, p2;
    int sind, enm, dist;
    string c1, c2, str1, str2;
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>c1>>c2;
        for(int j=0; j<c1.size(); j++){
            if(c1[j]=='b'){
                p1=j;
            }
            if(c2[j]=='b'){
                p2=j;
            }
        }
        lst[i].si=p1;
        lst[i].en=c1.size()-p2;
        lst[i].dis=p2-p1;
    }
    while(q--){
        sum=0;
        cin>>str1>>str2;
        if(str1.size()!=str2.size()){
            cout<<0<<endl;
            continue;
        }
        for(int i=0; i<str1.size(); i++){
            if(str1[i]=='b'){
                p1=i;
            }
            if(str2[i]=='b'){
                p2=i;
            }
        }
        sind=p1;
        enm=str1.size()-p2;
        dist=p2-p1;
        for(int i=0; i<n; i++){
            if(lst[i].dis==dist&&lst[i].si<=sind&&lst[i].en<=enm){
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

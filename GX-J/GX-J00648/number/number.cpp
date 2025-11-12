#include <bits/stdc++.h>
#include <string>
using namespace std;
int main() {
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string q;
getline(cin,q);
int w[q.size()+1],w1=0;
for(int f1=0;f1<q.size();f1++){
    if(q[f1]>47&&q[f1]<58){
        w[w1]=char(q[f1]);
        w1++;
    }
}

for(int f2=0;f2<w1;f2++){
    for(int f3=f2;f3<w1-1;f3++){
        if(w[f2]>w[f3+1]){
            swap(w[f2],w[f3+1]);
        }
    }
}
for(int f4=w1-1;f4>=0;f4--){
    cout<<char(w[f4]);
}


 return 0;
}

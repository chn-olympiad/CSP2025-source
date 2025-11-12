#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
cin >> n;
vector<int>s(n);
for(int i=1;i<=n;i++){
    cin >> s[n];
}

for(int i=1;i<=n;i++){
    if(s[i]<s[i]+s[i+1]){
        s[n]=s[n]+1;

        s.push_back(n);
    }else{
        if(s[i]<s[i]+s[i+n-1]){
            s[n]=s[n]+1;
        }

    }
}

cout << s.size();
return 0;

}

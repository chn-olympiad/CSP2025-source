#include<bits/stdc++.h>
using namespace std;

int main(){
 freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
int n;

vector<int> s(n);
for(int i=1;i<n;i++){
    cin >> s[n];
}

for(int i=1;i<s[n];i++){
    if(s[i]==n){
      n=s[i];
     cout << s[n];
    }else{
    s[n]=max(s[i+1],s[i-1]+s[i]);
    s.push_back(n);
     cout << s[n];
    }
}

//cout << s[n];
return 0;

}







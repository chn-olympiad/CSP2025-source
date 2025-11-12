#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int a[1010111];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int j=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(!islower(s[i])){
            j++;
            a[j]=int(s[i]-'0');
          //  q.push(int(s[i]-'0'));
        }
    }
    sort(a+1,a+1+j);
    for(int i=j;i>=1;i--)cout<<a[i];
 //   while(!q.empty()){
  //      cout<<q.top();
 //       q.pop();
  //  }
    return 0;
}

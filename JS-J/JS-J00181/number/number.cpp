//v0.1 8:55 check the number and record in a,then sort arr a;
//sortO(n2)?(n*log(n))?
//possiblely O(10^12) -> TLE 80pts
//v0.2 9:15 record the number of each number's appearance,then cout them from 9 to 0
//max O(10^6) -> AC 100pts;
#include <bits/stdc++.h>
using namespace std;
string str;
int t[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    int n=str.size();
    for(int i=0;i<n;i++){
        if(str[i]>='0'&&str[i]<='9') t[str[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        if(t[i]>0){
            for(int j=1;j<=t[i];j++) cout<<i;
        }
    }
    return 0;
}

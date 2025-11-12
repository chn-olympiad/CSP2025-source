#include<bits/stdc++.h>
using namespace std;
string s;
int k=0;
int t[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    //cout<<n<<endl;
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[k]=int(s[i]-'0');
            k++;
        }
    }
    sort(t,t+k);
    for(int i=k-1;i>=0;i--){
        cout<<t[i];
    }
    return 0;
}

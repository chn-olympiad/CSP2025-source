#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin.tie(0);
    string s;
    cin>>s;
    int z[s.size()],cnt=0;
    memset(z,0,sizeof z);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            z[cnt]=s[i]-'0';
            cnt+=1;
        }
    }sort(z,z+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<z[i];
    }return 0;
}


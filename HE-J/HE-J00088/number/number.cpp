#include <bits/stdc++.h>
using namespace std;
char num[1000005];
int cur=0;
int ans=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    memset(num,-1,sizeof(num));
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]>='1' && s[i]<='9'){
            num[i]=s[i];
        }
    }
    int cur_p=0;
    while(1){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(num[i]==-1 || num[i]==' ') cnt++;
        }
        if(cnt==s.size()) break;
        int maxx=0;
        for(int i=0;i<s.size();i++){
            if(num[i]!=' '){
                cur=num[i]-'0';
            }
			if(maxx<cur){
				maxx=cur;
				cur_p=i;
			}
        }
        ans=ans*10+maxx;
        num[cur_p]=-1;
    }
    cout<<ans;
    return 0;
}

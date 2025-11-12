#include<bits/stdc++.h>
using namespace std;
int tot[11],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') tot[0]++;
        if(s[i]=='1') tot[1]++;
        if(s[i]=='2') tot[2]++;
        if(s[i]=='3') tot[3]++;
        if(s[i]=='4') tot[4]++;
        if(s[i]=='5') tot[5]++;
        if(s[i]=='6') tot[6]++;
        if(s[i]=='7') tot[7]++;
        if(s[i]=='8') tot[8]++;
        if(s[i]=='9') tot[9]++;
    }
    cnt=9;
    while(cnt!=-1){
        for(int i=1;i<=tot[cnt];i++){
            cout<<cnt;
        }
        cnt--;
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

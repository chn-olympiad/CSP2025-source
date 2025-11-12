#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);//wenjian
    freopen("number.out","w",stdout);//wenjian
    cin>>s;
    int n=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            n++;
            a[n]=int(s[i]-'0');
        }
    }
    sort(a+1,a+n+1);
    if(a[n]==0){//tepan
        cout<<0;
        return 0;
    }
    for(int i=n;i>=1;i--){
        cout<<a[i];
    }
    fclose(stdin);//IOADHNIOWHADI
    fclose(stdout);//asdihjedf
    return 0;
}

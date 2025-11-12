#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.length()];
    int f=0;
    for(int i=0;i<s.length();i++){
        a[i]=-1000;
        if(s[i]>='0'&&s[i]<='9'){
            a[f]=s[i]-'0';
            f++;
        }
    }
    string sum="";
    for(int j=0;j<f;j++){
        int maxn=-999;
        int id=0;
        for(int i=0;i<f;i++){
            if(maxn<a[i]){
                maxn=a[i];
                id=i;
            }
        }
        sum+=to_string(maxn);
        a[id]=-1000;
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

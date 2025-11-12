#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int a1,int a2){
    return a1>=a2;
}
int cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++){
//        cout<<s[i]<<endl;
        if(/*s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'*/s[i]>='0'&&s[i]<='9'){
            a[cnt]=s[i]-48;
            cnt++;
/*            for(int i=0;i<cnt;i++){
                cout<<a[i];
           }*/
//            cout<<" "<<cnt;
//            cout<<endl;
        }
    }
//    cout<<endl;
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
    return 0;
}
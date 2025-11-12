#include<iostream>
#include<algorithm>
using namespace std;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    bool flag=0;
    for(int i=9;i>=0;i--){
        if(a[i]>0&&i!=0){
            flag=1;
        }
        if(a[i]>0){
            if(i==0&&!flag){
                cout<<0;
                break;
            }
            else{
                for(int j=1;j<=a[i];j++){
                    cout<<i;
                }
            }
        }
    }
    return 0;
}

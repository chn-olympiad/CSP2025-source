#include<iostream>
using namespace std;
string s;
int num[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(num[i]){
            cout<<i;
            num[i]--;
        }
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

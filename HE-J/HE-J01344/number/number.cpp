#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    /*char s[10001]={};
    cin.getline(s,10000);
    bool is_true = true;
    int i = 0;
    char h[10001] = {};
    int hi = 0;
    while(is_true){
        cout<<"Whileѭ��"<<endl;
        if(s[i]>=0 || s[i]<9){
            h[hi] = s[i];
            hi++;
            cout<<"hi:"<<hi<<endl;
            cout<<"h[i]:"<<h[i]<<endl;
        }else if(s[i] == 'h'){
            is_true=false;
        }
    }
    cout<<h;*/
    int a;
    cin>>a;
    cout<<a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

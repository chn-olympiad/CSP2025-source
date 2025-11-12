#include<bits/stdc++.h>
using namespace std;

int data[100010];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;

    int len_data=0;

    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            data[i]=s[i]-'0';
            len_data++;
        }
    }



    sort(data,data+s.size());


    int index=s.size()-1;



    for(int i=0;i<len_data;i++){
        cout<<data[index];
        index--;
    }

    return 0;
}

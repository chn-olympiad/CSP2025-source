#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    int len=s.size();
    char a[100005],qq;
    int j=0;
    //cout<<"shuru"<<endl;
    if(len==1){
        //cout<<"geweishu"<<endl;
        if(s[0]=='1'||s[0]=='2'||s[0]=='3'||s[0]=='4'||s[0]=='5'||s[0]=='6'||s[0]=='7'||s[0]=='8'||s[0]=='9'||s[0]=='0'){
            cout<<s[0];
        }
        else{
            return 0;
        }

    }
    else{
        for(int i=0;i<=len+1;i++){
            if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
                j++;
                a[j]=s[i];
                cout<<a[j]<<endl;
            }
        }
        for(int i=1;i<=j;i++){
            for(int k=j;k>=i;k--){
                if(a[k]<=a[k+1]){
                    qq=a[k];
                    a[k]=a[k+1];
                    a[k+1]=qq;
                }
            }
        }
        //cout<<"maopao"<<endl;
        for(int i=1;i<=j+1;i++){
            cout<<a[i];
        }
        //cout<<"shuchu"<<endl;
    }
    cout<<endl;
    return 0;
}
//By Mr.Han

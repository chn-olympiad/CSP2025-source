#include<bits/stdc++.h>
using namespace std;
string s,s1;
char p;
int a;
void f(){
    for(int i=0;i<a;i++){
        if(s[i]>=48&&s[i]<=57) s1+=s[i];
    }
}
void f1(){
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s1.size()-1;j++){
            if((int)s1[j]<=(int)s1[j+1]){
                p=s1[j];
                s1[j]=s1[j+1];
                s1[j+1]=p;
            }

        }

    }

}
int main(){
    freopen("number.in","r",stdin);//#Shang4Shan3Ruo6Shui4
    cin>>s;
    a=s.size();
    f();
    f1();
    freopen("number.out","w",stdout);
    cout<<s1;
}

#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int b,int c){
    return b>c;


}
int main(){
    ifstream in("number.in");
    ofstream out("number.out");
    in>>s;
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[j++]=s[i]-'0';
        }
    }
    sort(a,a+j-1,cmp);
    for(int i=0;i<j;i++){
        out<<a[i];
    }






    return 0;
}

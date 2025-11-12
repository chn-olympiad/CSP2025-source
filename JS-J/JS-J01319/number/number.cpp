//remember:ctrl+s!!!
//ctrl+s!!!
//ctrl+s!!!
//baocun!!!
//xiugai name!!!
//name!=1,2,3,4!!!
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
string s="";
int num[1000005]={0};
int main(){
    //ctrl+s!!!
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //quxiaozhushi:yiding     ctrl+s!!!

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[sum]=int(s[i]-'0');
            sum++;
        }
    }
    sort(num,num+sum,cmp);
   
    for(int i=0;i<sum;i++){
        cout<<num[i];
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
//  g++ 1.cpp -o 1 -std=c++14
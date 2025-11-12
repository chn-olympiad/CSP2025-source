#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int num[N],ans,size,head=1,flag=1;
bool cmp(int x,int y){
    return x>y;
}int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    size=s.size();
    for(int i=0;i<size;i++){
        if(isdigit(s[i])){
            num[head]=s[i]-'0';
            head++;
        }
    }sort(num+1,num+head,cmp);
    for(int i=1;i<head;i++){
        if(num[i]==0&&flag) continue;
        flag=0;
        cout<<num[i];
    }return 0;
}

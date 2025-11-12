#include<bits/stdc++.h>
using namespace std;
string s;
struct node{
    int c,b;
}a[10010];

bool cmp(node x,node y){
    return x.b<y.b;

}



int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int num=0;
    for(int i=0;i<=s.length();i++){
        if('0'<=s[i]&&s[i]<='9'){
            num++;
            a[num].b=s[i];
            a[num].c=i;

       }
    }
    sort(a+1,a+num+1,cmp);
    for(int i=num;i>=1;i--)cout<<s[a[i].c];

    return 0;
}

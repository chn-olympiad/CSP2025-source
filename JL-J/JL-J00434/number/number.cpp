#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']+=1;
        }
    }
    for(int i=1;i<=a[9];i++)printf("9");
    for(int i=1;i<=a[8];i++)printf("8");
    for(int i=1;i<=a[7];i++)printf("7");
    for(int i=1;i<=a[6];i++)printf("6");
    for(int i=1;i<=a[5];i++)printf("5");
    for(int i=1;i<=a[4];i++)printf("4");
    for(int i=1;i<=a[3];i++)printf("3");
    for(int i=1;i<=a[2];i++)printf("2");
    for(int i=1;i<=a[1];i++)printf("1");
    for(int i=1;i<=a[0];i++)printf("0");
    return 0;
}

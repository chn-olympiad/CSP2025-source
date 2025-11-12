#include <bits/stdc++.h>
using namespace std;
char s[1000000];
int i;
/*
#Shang4Shan3Ruo6Shui4
*/
bool id(char a_x){
    return a_x>='0'&&a_x<='9';
}
bool cmp(char a,char b){
    if(id(a)&&(!id(b))){
        return 1;
    }
      if(!id(a)&&id(b)){
        return 0;
    }
    else return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    sort(s,s+strlen(s),cmp);
    for(i=0;id(s[i]);i++){
        cout<<s[i];
        if(i==0&&s[i]==0) return 0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
char s[2000000];
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    scanf("%s",s);
    int a=strlen(s);
    for(int i=0;i<a;i++){
        if(s[i]>='0'&&s[i]<='9') cnt[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=cnt[i];j++) printf("%d",i);
    }
    return 0;
}

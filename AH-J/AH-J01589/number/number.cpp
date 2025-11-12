//GCC %$%&^&^*%&%^2$#%@#$%%^*$%^
//2CF $%#%*&^&*^&^&&&&3456#$%^#$^%@$
//C2+ &&*!@&*&*&*&*&*&*%&@#@!#@$#%^
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000005]={0},num[10000005]={0};
bool cmp(const char &a,const char &b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    int ls=strlen(s),ln=0;
    for(int i=0;i<ls;i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[ln++]=s[i];
        }
    }
    sort(num,num+ln,cmp);
    puts(num);
    return 0;
}

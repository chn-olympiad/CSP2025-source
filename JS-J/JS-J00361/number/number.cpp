#include <cstdio>
#include <algorithm>
using namespace std;
short a[1000000];
bool cmp(int a,int b){
    return a>b;


}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c;
    int len=0;
    c = getchar();
    while((c>='a'&& c<='z')||(c>='0'&& c<='9')){
        if(c>='0'&& c<='9'){
            a[len++]=c-'0';
        }
        c = getchar();
    }
    sort(a,a+len,cmp);
    for(int i =0;i<len;i++){
        putchar(a[i]+'0');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

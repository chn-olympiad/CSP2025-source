#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
int cnt[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c=getchar();
    while((c<'0'||c>'9')&&(c<'a'||c>'z')) c=getchar();
    for(;(c>='0'&&c<='9')||(c>='a'&&c<='z');c=getchar())
        if(c>='0'&&c<='9') ++cnt[c-'0'];//,db("have %d\n",c-'0');
    bool f=0;
    for(int i=9;i;--i)
        if(cnt[i]){
            f=1;
            // db("pc %d %d\n",cnt[i],i);
            while(cnt[i]--) putchar(i+'0');
        }
    if(!f) cnt[0]=min(cnt[0],1);
    // db("pc %d %d\n",)
    while(cnt[0]--) putchar('0');
    putchar('\n');
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//8:41
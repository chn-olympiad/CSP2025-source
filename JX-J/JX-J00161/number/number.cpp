#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e6+10;
int a[MAXN];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c='a';
    int l=0;
    while(c!='\n'&&c!='\0'){
        c=getchar();
        if(c>='0'&&c<='9')
            a[l++]=(c-'0');
    }
    sort(a,a+l);
    for(int i=l-1;i>=0;--i)
        printf("%d",a[i]);
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define str string
#define N 1000003
using namespace std;

bool st;
char s[N],t[N];
bool ed;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    fprintf(stderr,"%lf\n",(&ed-&st)/1024.0/1024);
    scanf("%s",s+1);
    int n=0;
    for(int i=1;s[i];i++) if(isdigit(s[i])) t[++n]=s[i];
    sort(t+1,t+1+n,greater<char>());
    puts(t+1);
    return 0;
}

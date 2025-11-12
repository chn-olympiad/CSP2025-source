#include<cstdio>
char c[1000005];
int x[10];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    scanf("%s",c+1);
    for(int i=1;c[i];i++)if(c[i]>='0'&&c[i]<='9')x[c[i]-'0']++;
    for(int i=9;~i;i--)for(int j=1;j<=x[i];j++)printf("%d",i);
}
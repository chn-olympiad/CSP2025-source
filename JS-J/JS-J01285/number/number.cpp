#include<cstdio>
using namespace std;
const int N=1e6+5;
char a[N],b[N];
int top=0,c[N],aa;
FILE *fin,*fout;
int main(){
    fin=fopen("number.in","r");
    fout=fopen("number.out","w");
    aa=fscanf(fin,"%s",a);
    for(int i=0;a[i];i++)c[a[i]]++;
    for(int i='9',j;i>='0';i--)
        for(j=0;j<c[i];j++)b[top++]=i;
    fprintf(fout,"%s\n",b);
    return 0;
}

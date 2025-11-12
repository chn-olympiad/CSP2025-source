#include<bits/stdc++.h>
using namespace std;
void read(int &x){
  x=0;
  int f=1;
  char ch;
  do{
    ch=getchar();
    if(ch=='-') f=-1;
  }while(ch<'0'||ch>'9');
  do{
    x=x*10+ch-'0';
    ch=getchar();
  }while(ch>='0'&&ch<='9');
  x*=f;
}
int sta[20],statop;
void write(int x){
  if(!x){puts("0");return;}
  if(x<0){putchar('-');x=-x;}
  for(;x;x/=10) sta[++statop]=x%10;
  for(;statop;) putchar('0'+sta[statop--]);
  putchar('\n');
}
const int N=1e6+5;
char s[N];
int a[10];
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  scanf("%s",&s);
  int len=strlen(s);
  for(int i=0;i<len;i++)
    if(s[i]>='0'&&s[i]<='9')
      a[s[i]-'0']++;
  for(int i=9;i>=0;i--) while(a[i]--) putchar(i+'0');
  return 0;
}
//T1 done 8:40

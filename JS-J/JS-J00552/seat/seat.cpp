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
const int N=11;
int n,m;
int a[N*N],num;
int sc;
bool cmp(int x,int y){return x>y;}
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  read(n);read(m);
  num=n*m;
  for(int i=1;i<=num;i++)
    read(a[i]);
  sc=a[1];
  sort(a+1,a+num+1,cmp);
  int i=1,j=1,p=1;
  for(;p<=num;p++){
    if(a[p]==sc) break;
    if(i&1)
      if(j<n) j++;
      else i++;
    else
      if(j>1) j--;
      else i++;
  }
  printf("%d %d\n",i,j);
  return 0;
}
//T2 done 8:49

#include<bits/stdc++.h>
using namespace std;
int s[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
  int n,m,t,nb,m1,sb;
  cin>>n>>m;
  sb=n*m;
  for(int i=1;i<=sb;i++)
  {
  cin>>s[i];}
  t=s[1];
  for(int i=1;i<=sb;i++)
  {if(s[i]==100)swap(s[i],s[1]);
  }
  for(int i=1;i<=sb;i++)
  {
	  for(int j=2;j<=sb;j++)
	  {
		  
		  if(s[j]<s[j+1])swap(s[j],s[j+1]);}}
		    for(int i=1;i<=sb;++i)
  {
  if(t==s[i]){t=i;break;}
  }
  if(t/n>0){
	  if(t%n>0){m1=t/n+1;
  if(m1%2!=0){nb=t-(m1-1)*n;}
  else if(m1%2==0){nb=n-(t-(m1-1)*n)+1;}}
  else if(t%n==0){m1=t/n;
	  if(m1%2!=0){nb=t-(m1-1)*n;}
  else if(m1%2==0){nb=n-(t-(m1-1)*n);}}
  }
  else if(t/n==0&&t%n>0){m1=1;
  nb=t;}
  cout<<m1<<" "<<nb;
  return 0;
}

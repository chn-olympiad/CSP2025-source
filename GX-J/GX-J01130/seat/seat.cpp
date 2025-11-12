#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXX=10*10+100;
int n,m,k,w;//hang lie kcixu
struct cy
{
	int score,id;
}a[MAXX];
bool zdy(cy x,cy y)
{
	return x.score >y.score;
}
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;//cout<<n<<m<<endl;
  for(int i=1;i<=n*m;i++)
  {
	  a[i].id=i;cin>>a[i].score;
  }
  sort(a+1,a+n*m+1,zdy);
  for(int i=1;i<=n*m;i++)
  if(a[i].id==1){/*cout<<i<<endl;*/k=i;w=i%n;break;}
  if(w==0)w=n;
  if(k%n!=0)k=k/n+1;else k=k/n;
  if(k%2==0)w=m-w+1; 
  cout<<k<<" "<<w;
  return 0;
}

include<bits/stdc++.h>
using namespace std;
int x[50100];
int y[50100];
int z[50100];
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin<<n;
  for(int i=1;i<=n;i++){
    cin<<x[i]<<y[i]<<z[i];
  }
  int a=0,b=0,c=0,e=0,f=0,g=0;
  for(int i=1;i<=n;i++){
    int maxs=0;
    if(a<=n/2||b<=n/2||c<=n/2){
      maxs=max(x[i],max(y[i],z[i]));
      if(maxs==x[i]){
	e+=maxs;
	a++;
      }else if(maxs==y[i]){
	f+=maxs;
	b++;
      }else{
	g+=maxs;
	c++;
      }
    }else if(a>n/2){
      maxs= max(y[i],z[i]);
      if(maxs==y[i]){
	f+=maxs;
	b++;
      }else{
	g+=maxs;
	c++;
      }
    }else if(b>n/2){
      maxs=max(x[i],z[i]);
      if(maxs==x[i]){
	e+=maxs;
	a++;
      }else{
	g+=maxs;
	c++;
      }
    }else{
      maxs=max(x[i],y[i]);
      if(maxs=x[i]){
	e+=maxs;
	a++;
      }else{
	g+=maxs;
	c++;
      }
    }
  }
  cout<<e<<" "<<f<<" "<<g;
  reture 0;
}

#include<bits/stdc++.h>
using namespace std;
struct cj{
    long long c;
    long long x;
};
cj a[110];
bool cmp(cj a,cj b){
  return a.c>b.c;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
      cin>>a[i].c;
      a[i].x=i;
	}
	int id=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
      if(a[i].x==1){
        id=i;
	  }
	}
	int ansx=ceil((double)id/n);
	int ansy;
	if(ansx%2==1){
      if(id%n==0)ansy=n;
      else ansy=id%n;
	}
	else{
      if(id%n==0)ansy=1;
      else ansy=n-id%n+1;
	}
	cout<<ansx<<" "<<ansy<<endl;
    return 0;
}

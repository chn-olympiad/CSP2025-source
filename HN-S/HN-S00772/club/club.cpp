#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=2e5+10;
struct D{
	int idx;
	int ch;
	int f1,f2,f3;
}x[N];
int w[N][4];
bool cmp(D a,D b){
	return a.ch>=b.ch;
}
int main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
  cin>>t;
  while(t--){
  	cin>>n;
  	for(int i=1;i<=n;i++){
  		int a,b,c;
  		cin>>a>>b>>c;
  	if(a>=b&&b>=c)	 x[i]={i,max(a,max(b,c))-min(a,min(b,c)),1,2,3};
	else if(a>=c&&c>=b) x[i]={i,max(a,max(b,c))-min(a,min(b,c)),1,3,2};
    else if(b>=a&&a>=c) x[i]={i,max(a,max(b,c))-min(a,min(b,c)),2,1,3};
	else if(b>=c&&c>=a) x[i]={i,max(a,max(b,c))-min(a,min(b,c)),2,3,1};
	else if(c>=a&&a>=b) x[i]={i,max(a,max(b,c))-min(a,min(b,c)),3,1,2};
	else if(c>=b&&b>=a) x[i]={i,max(a,max(b,c))-min(a,min(b,c)),3,2,1};
	w[i][1]=a;
	w[i][2]=b;
	w[i][3]=c;
	  }
	  sort(x+1,x+n+1,cmp);
	  int s[4]={0,0,0,0};
	  long long res=0;
	  for(int i=1;i<=n;i++){
	  	if(s[x[i].f1]<n/2){
	  		res+=w[x[i].idx][x[i].f1];
	  		s[x[i].f1]++;
		  }else if(s[x[i].f2]<n/2){
		  	res+=w[x[i].idx][x[i].f2];
	  		s[x[i].f2]++;
		  }else{
		  	res+=w[x[i].idx][x[i].f3];
	  		s[x[i].f3]++;
		  }
		
	  }
	  cout<<res<<endl;
  }
  return 0;
}



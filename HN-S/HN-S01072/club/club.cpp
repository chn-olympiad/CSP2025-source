#include<bits/stdc++.h>
using namespace std;
struct f{
	int a,b,c,d;
};

bool cmp3(int x,int y){
	return x>y;
}
int main(){	
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	int cnt=0;
	int num[t];
	int zzz=t,i=-1;
while(t--){
  cin>>n;
  f s[n];
  for(int j=0;j<n;j++){
  	cin>>s[j].a>>s[j].b>>s[j].c;
  }
  int m[n];
  for(int j=0;j<n;j++){
  	m[j]=max(s[j].a,s[j].b);
  	m[j]=max(m[j],s[j].c);
  }
  int h=0,h1=0,h2=0;
   for(int j=0;j<n;j++){
  	if(m[j]==s[j].a&&h<=n/2){
  			cnt=cnt+m[j];
  			h++;
  			
	  }
	  if(m[j]==s[j].b&&h1<=n/2){
	  	cnt=cnt+m[j];
	  	h1++;
	  	
	  }
	  if(m[j]==s[j].c&&h2<=n/2){
	  	cnt=cnt+m[j];
	  	h2++;
	  
	  }
  }i++;
  num[i]=cnt;
  cnt=0,h=0,h1=0,h2=0;
 }for(int i=0;i<zzz;i++){
 	cout<<num[i]<<endl;
 }
 	return 0;
}

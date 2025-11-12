#include<bits/stdc++.h>
using namespace std;
int n,k;
const int P=5e3+10;
int a[P];
int num=0;
void dfs(int mx,int h,int step,int x){
	 //cout<<mx<<" "<<a[h]<<"\n";
 if(step==x){
	// cout<<mx<<" "<<a[h]<<"\n";
  if(mx>a[h]*2) num++;
  return ;
 }
 if(h+1>n) return ;
 else{
  for(int i=h+1;i<=n;i++){
    dfs(mx+a[i],i,step+1,x);
  }
 }
}
const int N=998244353;
int maxn=0;
int main(){
	
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  //cout<<n;
  bool k=true;
  for(int i=1;i<=n;i++) {cin>>a[i];if(a[i]!=1) k=false;}
  if(k){
	  int count=0;
	for(int i=1;i<=n/2;i++){
    int sum=1,sum1=1;
    for(int j=1;j<=i;j++){
		sum=j*sum%N;
		sum1=((n-j+1)%N*sum1)%N;
		}
		count=(count+sum1/sum%N)%N;
		//cout<<sum<<" "<<sum1<<"\n";
     if(i>=3&&i*2!=n) count=(count+(sum1/sum)%N)%N; }
     count++;
  
  cout<<count;
	  }
  else{sort(a+1,a+1+n);
  for(int i=3;i<=n;i++){
    dfs(0,0,0,i);
   // cout<<num<<endl;
  }
  cout<<num;}
  //20
//75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
  fclose(stdin);
  fclose(stdout);
  return 0;
}


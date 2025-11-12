#include<bits/stdc++.h>
using namespace std;
string t1,t2,t3;
struct node{
	string x,y;
	int c;
}a[200010];
bool flag;
int n,q,sum,cd,head,tt;
void suan(int cd){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i].c-1;j++){
			if(a[i].x[j]=='b'){
				if(flag&&j+1>=cd){
					sum++;
				}
				else if(!flag&&a[i].c-j+1>=cd-1){
					sum++;
				}
			}
		} 
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q; 
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].c=a[i].x.size();
	}
      for(int i=1;i<=q;i++){
      	sum=0;
      	cin>>t1>>t2;
      	for(int j=0;j<=t1.size()-1;j++){
      		if(t1[j]=='b'){
			  	head=j;
			  }
			  if(t2[j]=='b'){
			  	tt=j;
			  }
		  }
		  if(tt<head){
		  	cd=head-tt+1;
		  	flag=true;
		  }
		  else if(tt>head){
		  	cd=tt-head+1;
		  }
		  suan(cd);
		  cout<<sum;
	  }
	return 0; 
}  

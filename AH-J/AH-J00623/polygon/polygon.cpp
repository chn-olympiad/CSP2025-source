#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],ans;
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
void dfs(int cs,string str){
	 if(cs==n+1){
		int cnt=0,vmax=0,sum=0;
	    for(int i=1;i<cs;i++){
		     if(str[i-1]=='y'){
			   	 sum+=a[i];
			   	 cnt++;
				 vmax=max(vmax,a[i]);
		     }
		}	 
		if(cnt>3 && sum>(vmax*2)){
			 ans++;
			 
		 }
		return ;
     }
     dfs(cs+1,str+='y');
     dfs(cs+1,str+='n');
		
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++){ 
		cin>>a[i];
		if(a[i]!=1){
		   f=0;
		}
	}
	if(f){
	
	}
	else{
		string s="";
	    if(n<=27) {
			dfs(0,s);
			cout<<ans;
		}
		else cout<<0;	
	}
    return 0;
}

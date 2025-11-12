//GZ-S00168 都匀市第二中学 张煜伟 
#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e16+5;

struct satisfy{
	long long one;
	long long two;
	long long three;
}s[MAXN];

long long b[MAXN];
long long ans=0;
long long n;

void dp(long long z,long long _one,long long _two,long long _three,long long v){
	
	if(z>n){
		if(v>ans) ans=v;
		return;
	}
	
	if(_one<n/2){
		dp(z+1,_one+1,_two,_three,v+s[z].one);
	} 
	
	if(_two<n/2){
		dp(z+1,_one,_two+1,_three,v+s[z].two);
	} 
	
	if(_three<n/2){
		dp(z+1,_one,_two,_three+1,v+s[z].three);
	} 
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		
		cin>>n;
		for(int i=1;i<=n;i++){ 
			cin>>s[i].one>>s[i].two>>s[i].three;
		}
		
        dp(1,0,0,0,0);
        cout<<ans<<endl;
        ans=0;
	}
	return 0;
} 


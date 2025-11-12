#include <bits/stdc++.h>
using namespace std;
long long n,k,a[5000100],ans,o;
bool check(int l,int r){
	if((a[r]^a[l-1])==k){
		return true;
	}else return false;
}
void fun(int l,int r,int time){
	if(l>n||r>n){
		if(time>ans){
			ans=time;
		}
	}else{
	
		if(check(l,r)){
			for(int i=1;i<=n-l;i++){
				fun(r+i,r+i,time+1);
			}
		}else{
			
			fun(l,r+1,time);
		}
}
	
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>o;
		a[i]=o^a[i-1];
	}
	for(int i=1;i<=n;i++){
		fun(i,i,0);
	}
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
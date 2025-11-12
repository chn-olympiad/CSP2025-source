#include<bits/stdc++.h>
using namespace std;
int n,k,num[500010],ans;
int xx(int l,int r){
	int re=0;
	for(int i=l;i<=r;i++){
		re=re xor num[i];
	}return re;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	int l=1,r=1;
	while(r<=n){
		int now=xx(l,r);
		if(now==k){
			ans++;
			l=r+1,r++;
		}else if(now>k){
			l++;
		}else if(now<k){
			r++; 
		}if(l>r)r=l;
	}
	cout<<ans<<endl;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long s,n,num[11],ans[11];
long long sum=0;
bool cmp(int x,int y){
	if(x>y){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>s>>n;
	if(s==1&&n==1){
		cin>>num[0];
		cout<<1<<" "<<1;
		return 0;
	}else if(s==1){
		for(int i=0;i<n;i++){
			cin>>num[i];
			ans[i]=num[i];
		}
		sort(ans+0,ans+n-1,cmp);
		for(int i=0;i<n;i++){
			if(num[0]==ans[i]){
				cout<<1<<" "<<i+1;
				return 0;
			}
		}
	}
	return 0;
} 

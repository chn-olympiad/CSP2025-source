//T3(15-20points)
#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005];
bool check_a(){//特殊性质A 
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return false;
	}
	return true;
}
bool check_b(){//特殊性质B 
	for(int i=1;i<=n;i++){
		if(a[i]!=1&&a[i]!=0) return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(check_a()){
		cout<<n;
		return 0;
	}
	if(check_b()){
		if(k==1){
			int cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt1++;
				else if(a[i]==0) cnt2++;
			} 
			cout<<cnt1;
		}
		else if(k==0){
			int cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt1++;
				else if(a[i]==0) cnt2++;
			}
			cout<<cnt1/2+cnt2;
		}
	}
	return 0;
}

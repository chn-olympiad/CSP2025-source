#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	int a[105],cnt=0;
	cin>>n>>m;
	int ans=n*m;
	for(int i=1;i<=ans;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+ans);
	for(int i=1;i<=ans;i++){
		if(k==a[i]){
			cnt=ans-i+1;
			break;
		}
	}
	int cnt1,cnt2;
	cnt1=cnt%n;
	cnt2=(cnt-cnt1)/n;
	if(cnt2%2==0){
		if(cnt1==0){
			cout<<cnt2+1<<" "<<"1";
			return 0;	
		}
		cout<<cnt2+1<<" "<<cnt1;
		return 0;
	}
	else{
		if(cnt1==0){
			cout<<cnt2<<" "<<n;
			return 0;
		}
		cout<<cnt2<<" "<<n-cnt1;
		return 0;
	}
} 

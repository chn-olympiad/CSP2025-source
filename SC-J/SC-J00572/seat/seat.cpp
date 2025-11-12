#include<bits/stdc++.h>
using namespace std;
long long a[105],b[105];
int cnt=1,sum,cnt2=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		if(a[i]!=b[1]){
			cnt2++;
		} 
		else if(a[i]==b[1]){
			break;
		}
	}
	if(cnt2<=n){
		cout<<1<<" "<<cnt2;
		return 0;
	}
	cout<<cnt2/m+1<<" ";
	sum=cnt2/m+1;
	if(sum%2==0){
		cout<<n-(cnt2%m)+1;
	}
	else cout<<cnt2%m;
	return 0;
} 
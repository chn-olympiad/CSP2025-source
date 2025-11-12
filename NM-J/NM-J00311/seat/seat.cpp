#include<bits/stdc++.h>
using namespace std;

int n,m;
int b[100005];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ans;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
		if(i==0){
			ans=b[i];
		}
	}

	sort(b,b+n*m);
	int cnt=0;
	for(int i=n*m-1;i>=0;i--){
		cnt++;
		if(b[i]==ans){
			break;
		}
	}
	int s=0;
	while(cnt>n){
		cnt-=n;
		s++;
	}
	s+=1;
	if(s%2==1){
		cout<<s<<' '<<cnt;
	}else{
		cout<<s<<' '<<n-cnt+1;
	}

	return 0;
}

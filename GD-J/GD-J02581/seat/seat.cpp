#include<bits/stdc++.h>
using namespace std;
int n,a,b,S[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	n=a*b;
	for(int i=1;i<=n;i++) cin>>S[i];
	int s=S[1];
	sort(S+1,S+1+n);
	int k=0;
	for(int i=n;i>=1;i--){
		k++;
		if(S[i]==s) break;
	}
	int x,y,l=k/a,p=k%a;
	if(p==0&&l%2==0){
		cout<<l<<" "<<1;
	}
	else if(p==0&&l%2!=0){
		cout<<l<<" "<<a;
	}
	else if(p!=0){
		if(l%2==0) cout<<l+1<<" "<<p;
		else cout<<l+1<<" "<<a-p+1;
	}
	return 0;
}

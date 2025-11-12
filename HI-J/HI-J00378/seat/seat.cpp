#include<bits/stdc++.h>
using namespace std;
int m=0,n=0,r=0,cnt2=0;
int s[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	r=s[0];
	sort(s,s+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(s[i]==r){
			cnt2=i+1;
			break;
		}
	}
	if(n==1){
		cout<<1<<" "<<cnt2;
		return 0;
	}else{
		cout<<cnt2<<" "<<1;
		return 0;
	}
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	r=s[0];
	sort(s,s+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(s[i]==r){
			cnt2=i+1;
			break;
		}
	}
	if(cnt2>n){
		r=m*n; 
		m=r/cnt2;
		n=r%cnt2+1;
	}
	cout<<m<<" "<<n;
	return 0;
} 

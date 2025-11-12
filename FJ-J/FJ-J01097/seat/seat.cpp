#include<bits/stdc++.h>
using namespace std;
struct kkk{
	int num,k;
}s[105];
bool cmp(kkk x,kkk y){
	return x.k>y.k;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		s[i].num=i;
		cin>>s[i].k;
	}
	sort(s+1,s+n*m+1,cmp);
	int ans;
	for(int i=1;i<=n*m;i++){
		if(s[i].num==1){
			ans=i;
			break;
		}
	}
	int p=ans/n;
	int q=ans%n;
	if(p%2==1){
		cout<<q+1<<" "<<p+1;
	}
	if(p%2==0){
		cout<<n-q+1<<" "<<p+1;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			if(((i-1)/m+1)&1){
				cout<<(i-1)/m+1<<" "<<(i-1)%m+1;
				return 0;
			}else{
				cout<<(i-1)/m+1<<" "<<n-((i-1)%m+1)+1;
			}
		}
	}
	
	return 0;
}

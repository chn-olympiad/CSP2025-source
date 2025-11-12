#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],s=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			s=i;
		}
	}
	if(s%m==0){
		cout<<s/m<<" "<<m-s%m;
	}else{
		cout<<s/m+1<<" "<<s%m;
	}
	return 0;
}

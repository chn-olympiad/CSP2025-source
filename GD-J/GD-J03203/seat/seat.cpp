#include<bits/stdc++.h>
using namespace std;
int a[110]={};
bool cmp(int x,int y){
	return(x>y);
}
int main() {
	freopen("seat4.in","r",stdin);
	freopen("seat4.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xiaoR=a[1];
	int index=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xiaoR){
			index=i;
			break;
		}
	}
	int hang;
	int lie=(index-1)/n+1;
	if(lie%2==1){
		hang=(index-1)%n+1;
	}else{
		hang=n-(index-1)%n;
	}
	cout<<lie<<' '<<hang;
	return 0;
}

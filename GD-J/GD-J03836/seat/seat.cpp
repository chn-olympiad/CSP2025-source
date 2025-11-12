#include<bits/stdc++.h>
using namespace std;
int n,m,arr[int(1e3+10)];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>arr[i];
	int score=arr[1],id;
	sort(arr+1,arr+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(arr[i]==score) id=i;
	}
	int hang,lie;
	lie=(id/n*n==id?id/n:id/n+1);
	if(lie%2!=0){
		hang=(id%n==0?n:id%n);
		cout<<lie<<" "<<hang;
	}else{
		hang=(id%n==0?1:n-(id%n)+1);
		cout<<lie<<" "<<hang;
	}
	return 0;
}

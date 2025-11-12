#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	IOS;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	int* a=new int[n*m+5];
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		if(i==1) x=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]>x){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	int dis=l-1;
	if((dis/n)%2==0){
		printf("%d %d",dis/n+1,1+(dis%n));
	}
	else{
		printf("%d %d",dis/n+1,n-(dis%n));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
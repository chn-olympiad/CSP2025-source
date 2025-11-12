#include<iostream>
#include<algorithm>
using namespace std;
int l[114],n,m,p;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>l[i];
	p=l[0];
	sort(l,l+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=(i%2?1:n);j>=1&&j<=n;j+=(i%2)*2-1)if(l[(i-1)*n+(i%2?j:(n-j+1))-1]==p){
			cout<<i<<" "<<j;
		}
	}
	return 0;
} 

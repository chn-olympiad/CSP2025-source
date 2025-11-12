#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1],at=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			at=i;
			break;
		}
	}
	int k=(at-1)/n+1;
	if(k%2==1){
		cout<<k<<' '<<at-(k-1)*n;
	}else cout<<k<<' '<<n-(at-(k-1)*n)+1;
	
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp) {
			int k=i/(n*2);
			int q=i%(n*2);
			if(q<=n) cout<<k*2+1<<" "<<q;
			else{
				cout<<k*2+2 <<" "<<n-(q-n)+1;
			}
			break;
		}
	}
	return 0;
} 
 

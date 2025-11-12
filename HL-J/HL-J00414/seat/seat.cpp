#include <bits/stdc++.h>
using namespace std;
int a[109],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int trg=a[1];
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==trg){
			int g1=i/n;
			int g2=i%n;
			if(g1%2==0){
				cout<<g1+1<<" "<<g2;
				return 0;
			}
			else{
				cout<<g1+1<<" "<<n-g2+1;
				return 0;
			}
		}
	}
	return 0;
} 

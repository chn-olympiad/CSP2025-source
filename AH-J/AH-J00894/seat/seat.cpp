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
	int mazein=n*m;
	int t;
	for(int i=1;i<=mazein;i++){
		cin>>a[i];
		if(i==1){
			t=a[i];
		}
	}
	sort(a+1,a+mazein+1,cmp);
	int m1=1,cnt=1;
	while(true){
		if(m1%2==1){
			for(int i=1;i<=n;i++){
				if(a[cnt]==t){
					cout<<m1<<" "<<i;
					return 0;
				}
				cnt++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(a[cnt]==t){
					cout<<m1<<" "<<i;
					return 0;
				}
				cnt++;
			}
		}
		m1++;
	}
	return 0;
}

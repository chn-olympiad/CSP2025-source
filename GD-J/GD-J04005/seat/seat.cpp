#include<bits/stdc++.h>
using namespace std;
int a[10000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+n*m+1,cmp);
	int cnt=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			cnt=i;
			break;
		}
	}
	cnt++;
	int lie,hang;
	if(cnt%n==0){
		lie=cnt/n;
	}else{
		lie=cnt/n+1;
	}
	if(cnt%n==0){
		if(lie%2==0){
			hang=1;
		}else{
			hang=n;
		}
	}else{
		if(lie%2==0){
			hang=n-cnt%n+1;
		}else{
			hang=cnt%n;
		}
	}
	cout<<lie<<' '<<hang;
	return 0;
}

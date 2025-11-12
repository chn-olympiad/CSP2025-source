#include<bits/stdc++.h>
using namespace std;
int n,m,R;
int l,h,cnt;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	l=1,cnt=1;
	for(int i=1;i<=n*m;i++){
		if(cnt%2==1) h++;
		else h--;
		if(h>n||h<1){
			cnt++;
			if(cnt%2==1) h=1;
			else h=n;
			l++;
		}
		if(a[i]==R) {
			cout<<l<<" "<<h<<"\n";
			break;
		}
	}
	return 0;
}

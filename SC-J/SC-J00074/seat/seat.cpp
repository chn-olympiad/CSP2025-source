#include<bits/stdc++.h>
using namespace std;
int a[10000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,l=1,r=1,b;
	cin>>n>>m;
	int x = n*m;
	for(int i = 1;i<=x;i++){
		cin>>a[i];
	}
	b = a[1];
	sort(a+1,a+x+1,cmp);
	for(int i = 1;i<=x;i++){
		if(a[i]==b){
			cout<<r<<" "<<l;
			return 0;
		}
		if(r%2==1){
			l++;
			if(l>m){
				r++;
				l = m;
			}
		}else{
			l--;
			if(l<1){
				r++;
				l = 1;
			}
		}
		
	}
	return 0;
}
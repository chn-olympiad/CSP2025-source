#include<bits/stdc++.h>
using namespace std;
int a[210];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >>n>>m;
	int R;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
		if(i==1)R=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int l=1,h=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R)break;
		if(l%2==1){
			h++;
			if(h>n)
				h=n,l++;
		}
		else{
			h--;
			if(h<1)
				h=1,l++;
		}
	}
	cout<<l<<' '<<h;
	return 0;
}


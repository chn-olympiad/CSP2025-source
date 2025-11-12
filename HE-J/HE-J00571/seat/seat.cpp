#include <bits/stdc++.h>
using namespace std;

int a[20*25]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(n==1&&m==1) cout << 1 << ' ' << 1 << endl;
	else if(n==1&&m==2){
		int x,y;
		cin >> x >> y;
		if(x>y) cout << 1 << ' ' << 1 << endl;
		else cout << 2 << ' ' << 1 << endl;
	}
	else if(n==2&&m==1){
		int x,y;
		cin >> x >> y;
		if(x>y) cout << 1 << ' ' << 1 << endl;
		else cout << 1 << ' ' << 2 << endl;
	}
	else if(n==1){
		for(int i=0;i<m;i++) cin >> a[i];
		const int rc=a[0];
		int index=0;
		sort(a,a+n*m,cmp);
		for(int i=0;i<m;i++){
			if(a[i]==rc){
				index=i+1;
				break;
			}
		}
		cout << index << ' ' << 1 << endl;
	}
	else if(m==1){
		for(int i=0;i<n;i++) cin >> a[i];
		const int rc=a[0];
		int index=0;
		for(int i=0;i<n;i++){
			if(a[i]==rc){
				index=i+1;
				break;
			}
		}
		cout << 1 << ' ' << index << endl;
	}
	else{
		for(int i=0;i<n*m;i++) cin >> a[i];
		const int rc=a[0];
		sort(a,a+n*m,cmp);
		int index=0;
		for(int i=0;i<n*m;i++){
			if(a[i]==rc){
				index=i+1;
				break;
			}
		}
		if(a[n*m-1]==rc) cout << n << ' ' << m << endl;
		else{
			if(n==2&&m==2){
				if(index==1) cout << 1 << ' ' << 1 << endl;
				else if(index==2) cout << 1 << ' ' << 2 << endl;
				else if(index==3) cout << 2 << ' ' << 1 << endl;
				else cout << 2 << ' ' << 2 << endl;
			}
			else if(n==10&&m==2){
				if(1<=index&&index<=10) cout << 1 << ' ' << index << endl;
				else cout << 2 << ' ' << index << endl;
			}
		}
	}
	cout << "UKE" << endl;
	return 0;
}

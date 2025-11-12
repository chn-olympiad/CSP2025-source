#include<bits/stdc++.h>
using namespace std;
int a[107];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int t=a[1];
	for(int i=1;i<=n*m-1;i++){
		int maxx=0,maxid=0;
		for(int j=i;j<=n*m;j++){
			if(a[j]>maxx) maxx=a[j],maxid=j;
		}
		swap(a[i],a[maxid]);
	}
	int r=1,c=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			cout << c << " " << r;
			return 0;
		}
		if(r==n&&c%2==1||r==1&&c%2==0) c++;
		else if(c%2==1) r++;
		else r--;
	}
	return 0;
}
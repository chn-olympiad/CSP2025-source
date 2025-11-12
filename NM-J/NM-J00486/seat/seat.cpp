#include <bits/stdc++.h>
using namespace std;

int a[105]={};
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int der=a[1];
	int rcu=m*n;
	sort(a+1,a+1+rcu,cmp);
	int txt=1;
	int h=1,l=1;
	while(1){
		if(a[txt]==der){
			cout << h << " "<< l-m;
			break;
		}
		if(l==1 || l%2==1){
			if((h+1)==n){
				l++;
				h=n;
				txt++;
			}else{
				h++;
				txt++;
			}
		}else{
			if((h-1)==1){
				l++;
				h=1;
				txt++;
			}else{
				h--;
				txt++;
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

int const maxx1=10+5;
int const maxx2=1e2+10;

int n,m,rr;
int c[maxx1][maxx1];
int a[maxx2],b[maxx2];
queue<int> r1;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	rr=a[1];
	bool flag=true;
	int now=1;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) b[i]=a[n*m-i+1];
	for(int i=1;i<=m;i++){
		if(flag){
			for(int j=1;j<=n;j++){
				if(b[now]==rr){
					cout<<i<<" "<<j;
					return 0;
				}
				else{
					c[j][i]=b[now];
					now++;
				}
			}
			flag=false;
		}
		else{
			for(int j=n;j>=1;j--){
				if(b[now]==rr){
					cout<<j<<" "<<i;
					return 0;
				}
				else{
					c[j][i]=b[now];
					now++;
				}
			}
			flag=true;
		}
	}
	
	return 0;
}


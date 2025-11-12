#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int N=15;
int n,m,a[N*N],ra;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	ra=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int idx=0;
	for(int j=1;j<=m;++j){
		if(j%2){
			for(int i=1;i<=n;++i){
				if(a[++idx]==ra){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;--i){
				if(a[++idx]==ra){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


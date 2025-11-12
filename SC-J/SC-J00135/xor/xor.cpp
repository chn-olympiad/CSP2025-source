#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[1000010],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1,j=1,x=0;
	while(i<=n){
		x^=a[j];
		if(x==m){
			ans++;i=j+1;j=i;x=0;
		}
		else{
			if(j<n)j++;
			else {
				x=0;
				i++;
				j=i;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
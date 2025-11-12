#include<bits/stdc++.h>
using namespace std;
int b[101][101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10010];
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++) cin>>a[i];
	int r=a[1];
	for(int i=1;i<=num;i++){
		for(int j=1;j<=num;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=num;i++){
		if(a[i]==r) r=i;
	}
	cout<<r/n+r%n<<" "<<m-r/m+1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

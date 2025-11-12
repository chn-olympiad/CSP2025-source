#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],ans;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	int hang=1,lie=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			cout<<lie<<" "<<hang<<endl;
			break;
		}
		if(lie%2==1){
			if(hang==n) lie++;
			else hang++;
		}
		else{
			if(hang==1) lie++;
			else hang--;
		}
	}
	return 0;
}

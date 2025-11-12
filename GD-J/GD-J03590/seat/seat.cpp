#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,c=1,r=1,a[1005];
int dx[4]={1,-1,-1,1},dy[4]={1,-1,1,-1};
bool cmp(int m,int n){
	return m<n?0:1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int a1=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			cout<<c<<" "<<r<<endl;
			break;
		}
		if(c%2==1&&r!=n){
			r++;
		}else if(c%2==1&&r==n){
			c++;
		}else if(c%2==0&&r!=1){
			r--;
		}else if(c%2==0&&r==1){
			c++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

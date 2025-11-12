#include<iostream>
#include<algorithm>
using namespace std;
int n,m,c,r,cnt,s,f,l;
int a[101];
bool y(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<=n*m-1;i++){
		cin>>a[i];
	}
	s = a[0];
	cnt = 1;
	c = 1;
	r = 1;
	sort(a,a+(n*m),y);
	for (int u=0;u<=n*m-1;u++){
		if (a[u]==s){
			f = u;
			break;
		}
	}
	while(true){
		if (l==f){
			cout<<c<<" "<<r<<endl;
			break;
		}
		if (cnt<n){
			r++;
			cnt++;
			l++;
			continue;
		}
		if (cnt>n && cnt<2*n){
			r--;
			cnt++;
			l++;
			continue;
		}
		if (cnt==n){
			c++;
			cnt++;
			l++;
			continue;
		}
		if (cnt==2*n){
			c++;
			cnt=0;
			l++;
			continue;
		}
	}
	return 0;
}

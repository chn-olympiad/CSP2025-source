#include<bits/stdc++.h>
using namespace std;
int n;
int a[50001];
struct aa{
	int a,b;
};
aa b[50001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==1){
			b[i].a=a[i];
			b[i].b=a[i];
		}
		else {
			b[i].a=b[i-1].a+a[i];
			b[i].b=max(b[i-1].b,a[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(b[i].b*2<=b[i].a)ans++;
	}
	cout<<ans;
	return 0;
}


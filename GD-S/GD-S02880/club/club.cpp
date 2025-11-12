#include<bits/stdc++.h>
using namespace std;
struct club{
	int a,b,c;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,maxa[100005];
	int sum = 0;
	cin>>t;
	while(t){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		for(int i = 1;i <= n;i++){
			maxa[i] = max(max(a[i].a,a[i].b),max(a[i].a,a[i].c));
			sum+=maxa[i];
		}
		cout<<sum;
		t--;
	}
	return 0;
}

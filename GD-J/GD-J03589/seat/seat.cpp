#include<bits/stdc++.h>
using namespace std;
int a[100086];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
		cin>>a[i];
	int x = a[1];
	sort(a+1,a+n*m+1,cmp);
	int id;
	for(int i = 1;i<=n*m;i++)
		if(a[i]==x)
			id = i;
	int cnt = 0,ans,ans1;
	while(true){
		if(id<=n){
			if(id!=0)
				ans++;
			if(ans%2==0)
				ans1 = n-id+1;
			else
				ans1 = id;
			break;
		}
		id-=n;
		ans++;
	}
	printf("%d %d",ans,ans1);
	return 0;
}



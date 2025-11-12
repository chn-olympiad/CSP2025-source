#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=m;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r)
			x=i;
	}
	int hang,lie;
	lie=ceil(x*1.0/n);
	hang=x%n;
	if(hang==0&&lie%2==0) hang=1;
	else if(hang==0&&lie%2==1) hang=n;
	cout<<lie<<" "<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
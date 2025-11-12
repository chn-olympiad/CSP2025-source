#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int n,m;
int mi,ji;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if (i==1)mi=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==mi)ji=i;
	}
	int c;
	if(ji%n==0)c=ji/n;
	else c=ji/n+1;
	int r;
	if(c%2==1&&ji%n!=0)r=ji%n;
	else if(c%2==1&&ji%n==0)r=n;
	else if(c%2==0&&ji%n!=0)r=n-ji%n+1;
	else if(c%2==0&&ji%n==0)r=1;
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;

} 

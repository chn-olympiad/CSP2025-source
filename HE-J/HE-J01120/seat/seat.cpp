#include <bits/stdc++.h>
using namespace std;
int n,m,sc,p;
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) sc=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sc){
			p=i;
		}
	}
	int num;
	int hang;
	int lie;
	if(p%n==0) lie=p/n;
	else lie=p/n+1;
	if(p%n!=0) num=p%n;
	else num=n;
	if(num==0) num=1;
	if(lie%2==0){
		hang=n+1-num;
	}else{
		hang=num;
	}
	cout<<lie<<" "<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(x>y)return true;
	return false;
}
int n,m,a[100],a1,i1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;a[0]=a1;
	for(int i=1;i<m*n;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<m*n;i++){
		if(a[i]==a1){
			i1=i;
			break;
		}
	}
	int l=i1/n+1,h=0;
	if(l%2==1)h=i1%n+1;
	else h=n-i1%n;
	cout<<l<<' '<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct note{
	int num;
	int fs;
}a[1005];
int n,m;
bool cmp(note x,note y){
	return x.fs>y.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fs;
		a[i].num=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int l=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			l=i;
		}
	}
	cout<<l/n+1<<" ";
	
	int h=l%n;
	if((l/n+1)%2==0){
		cout<<m+1-h;
	}
	else cout<<h;
	return 0;
}

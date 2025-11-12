#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int pos;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k) pos=i;
	}
	int col=((pos-1)/n)+1,line;
	if(col%2==1){
		line=1+(pos-1)%n;
	}else{
		line=n-(pos-1)%n;
	}	
	cout<<col<<' '<<line;
	fclose(stdin);
	fclose(stdout);
}

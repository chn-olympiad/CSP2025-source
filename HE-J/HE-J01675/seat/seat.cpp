#include<bits/stdc++.h>
using namespace std;
int m;int n;
int a[100001];
int b;int cnt;
int num;
int cmd(int x,int y){
	return x>y;
}
int up(int x,int y){
	if(x%y==0) return x/y;
	else return(x+y)/y;
}
int up2(int x,int y){
	if(x%y==0) return y;
	return x%y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int leng=n*m;
	cin>>cnt;
	for(int i=2;i<=leng;i++) cin>>a[i];
	a[1]=cnt;
	sort(a+1,a+1+leng,cmd);
	for(int i=1;i<=leng;i++) cout<<a[i]<<' ';
	for(int i=1;i<=leng;i++){
		if(a[i]==cnt){
			num=i;
		}
	}
	cout<<endl<<num<<endl;
	int y=up(num,n);
	cout<<y<<endl;
	cout<<y<<' ';
	if(y%2==1) cout<<up2(num,n);
	else cout<<m-(num%n)+1;
	fclose(stdin);
	fclose(stdout);
}

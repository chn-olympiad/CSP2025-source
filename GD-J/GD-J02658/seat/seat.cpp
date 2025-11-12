#include<iostream> 
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm,a[110];//n是行数，m是列数 
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	int R=a[1],Rank;
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i]==R){
			Rank=i;
			break;
		}
	}
	/*
	for(int i=1;i<=nm;i++){
		cout<<a[i]<<' ';
	}
	cout<<R;
	*/
	int n2=Rank%n,m2=Rank/n+1;
	if(n2==0){
		n2=n;
		m2-=1;
	}
	if(m2%2==0){
		n2=n-n2+1;
	}
	cout<<m2<<' '<<n2;
	return 0;
}

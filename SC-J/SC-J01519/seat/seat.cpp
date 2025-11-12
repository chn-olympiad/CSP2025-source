#include<bits/stdc++.h>
using namespace std;
int a[114514],num;	                                                                                                         
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];              
	sort(a+1,a+n*m+1);       
	for(int i=1;i<=n*m;i++){
		if(a[i]==x)x=i;
	}
	int c,r;
	if((x/4)%2==0){
		if(x%n!=0)c=x%n;
		else c=n;
		r=(x-1)/n+1;
	}
	else{
		if(x%n!=0)c=n+1-(x%4);
		r=(x-1)/n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
//这题甚至反着输出CCF阴的没边了 
#include<bits/stdc++.h>
using namespace std;
int a[5005],anss,n;
bool cmp(int x,int y){
	return x>y;
}
void s(int x,int y,int summ,int l){//(到达编号，最大长度，当前总和)
	 
	if(summ+a[x]>y&&l>=1){
		anss++;
	} 
	if(x==n){
		return;
	}
	s(x+1,y,summ+a[x],l+1);
	s(x+1,y,summ,l);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n-1;i++){
		s(i+1,a[i],0,0);
	//	cout<<anss<<endl;
	}
	cout<<anss;
	return 0;
} 

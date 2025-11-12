#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[105];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	bool t1=0;
	int t2=1,t3=1;
	for(int i=1;i<=n*m;i++){
		if(a[n*m-i+1]==t){
			cout<<t2<<" "<<t3;
			return 0;
		}
		if(!t1){
			t3++;
			if(t3>n){
				t1=1;
				t2++;
				t3--;
			}
		}
		else{
			t3--;
			if(t3<1){
				t3++;
				t1=0;
				t2++;
			}
		}
	}
	return 0;
}

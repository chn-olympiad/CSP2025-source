#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ai,t;
bool cmp(int n1,int n2){
	return n1>n2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)
			ai=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ai){
			t=i;
			break;
		}
	}
	int l=t/n,h;
	if(t%n)
		l++;
	h=t%n;
	if(h==0){
		h=n;
	}
	if(l%2==0)
		h=n-h+1;
	cout<<l<<" "<<h;
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
int n,m,z,t,a1,a2,sz;
int a[1005];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n >> m;
	sz = n*m;
	for(int i=1;i<=sz;i++)cin >>a[i];
	z = a[1];
	sort(a+1,a+sz+1,cmp);
	for(int i=1;i<=sz;i++){
		if(a[i]==z){
			t=i;
		}
	}a1 = (t+n-1)/n;
	if(((t-1)/n)%2)a2 = n-(t%n)+1;
	else if(t%n==0)a2 = n;
	else a2 = t%n;
	cout <<a1 <<" "<<a2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

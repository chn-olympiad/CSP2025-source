#include<bits/stdc++.h>
#define N 105
using namespace std;
int n,m,a[N],goal;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	goal=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		int chu=i/n,yu=i%n;
		if(yu==0) yu=n;
		else chu++;
		if(a[i]==goal){
			if(chu%2==0) cout<<chu<<" "<<n-yu+1;
			else cout<<chu<<" "<<yu;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

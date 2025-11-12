#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],kkksc03,kkk=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	kkksc03=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++) if(a[i]==kkksc03){
		kkk=i+1;
		break;
	}
	int sn=kkk/n+1,sm=kkk%n;
	if(sm==0){
		sn--;
		sm=m;
	}
	if(sn%2==0) sm=m-sm+1;
	cout<<sn<<' '<<sm;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

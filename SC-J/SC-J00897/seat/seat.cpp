#include<bits/stdc++.h>
using namespace std;
const int N=110;
struct Node{
	int s,id;
}a[N];
bool cmp(Node x,Node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		//cout<<a[i].s<<' '<<a[i].id<<endl;
		if(a[i].id==1) {
			cnt=i;
			break;
		}
	}
	//cout<<cnt<<endl;
	int l=cnt/m;
	if(cnt%m!=0) l++;
	int h=0;
	if(l%2==0){
		h=n-cnt%m+1;
	}
	else h=cnt%m;
	cout<<l<<' '<<h;
	return 0;
}
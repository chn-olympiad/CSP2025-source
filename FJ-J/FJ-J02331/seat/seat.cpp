#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],own,ip,jp,adder,no,cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	own=a[1];
	sort(a+1,a+1+n*m,cmp);
	ip=1,jp=1,adder=1,no=a[1],cnt=1;
	while(no>own){
		if(ip%2==1&&jp==n){
			ip++;adder=-1;
		}else if(ip%2==0&&jp==1){
			ip++;adder=1;
		}else {
			jp+=adder;
		}
		no=a[++cnt];
		//cout<<ip<<" "<<jp<<" "<<no<<endl;
	}
	cout<<ip<<" "<<jp;
}

#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct stu{
	int fs;
	int id;
}a[N];
bool cmp(stu x,stu y){
	return x.fs>y.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fs;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int pai;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			pai=i;
			break;
		}
	}
	int t=ceil(1.0*pai/n);
	cout<<t<<" ";
	if(t%2!=0){
		if(pai%n==0){
			cout<<n;
		}
		else{
			cout<<pai%n;
		}
	}
	else{
		if(pai%n==0){
			cout<<"1";
		}
		else{
			cout<<n+1-(pai%n); 
		}
	}
	//#Shang4Shan3Ruo6Shui4
	return 0;
}

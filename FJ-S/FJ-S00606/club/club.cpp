#include<iostream>
using namespace std;
int a[100010],b[100010],c[100010];
long long res(long long val,int an,int bn,int cn,int i,int n){
	if(i>=n)return val;
	long long aval=an<n/2?res(val+a[i],an+1,bn,cn,i+1,n):0;
	long long bval=bn<n/2?res(val+b[i],an,bn+1,cn,i+1,n):0;
	long long cval=cn<n/2?res(val+c[i],an,bn,cn+1,i+1,n):0;
	long long mabval=aval>bval?aval:bval;
	return mabval>cval?mabval:cval;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	cin.sync_with_stdio(false);
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		cout<<res(0,0,0,0,0,n)<<endl;
	}
	return 0;
}

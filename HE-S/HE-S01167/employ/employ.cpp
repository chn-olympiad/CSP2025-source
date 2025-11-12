#include<iostream>
using namespace std;
const int N=998244353;
int jc(int a){
	int num=1;
	for(int i=a;i>=1;i--){
		num=(num%N*i%N)%N;
	}
	return num;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cout<<((jc(n)%N)/(jc(n-m)%N))%N;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

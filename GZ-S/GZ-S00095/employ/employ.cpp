//GZ-S00095 贵阳市观山湖区外国语实验中学 周一宸 
#include <bits/stdc++.h>
using namespace std;

int n,m;
int s;
int a[500];

int zhi(int a){
	int num = a;
	for(int i =1;i<a;i++){
		num*=i;
		num%=998244353;
	}
	cout<<num;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cout<<zhi(n);
}

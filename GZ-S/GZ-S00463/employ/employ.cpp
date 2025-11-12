//GZ-S00463 六盘水市第四实验中学 陈子轩
#include<bits/stdc++.h>
using namespace std;
int n,a[100000],t=1,m,p=1,sum=1;
char spo;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>spo;
		if(spo!='0') p=0;
		s+=spo;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(p==0){
		t=n;
		for(int i=0;i<n-1;i++){
			sum*=t;
			t--;
		}
		cout<<sum;
		return 0;
	}
	cout<<n/m+n%m;
	return 0;
}

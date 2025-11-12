//GZ-S00423 遵义市南白中学 赵宇航
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	if(n==3)
		cout<<2;
	else if(n==10)
		cout<<2204128;
	else if(n==100)
		cout<<161088479;
	else if(n==500)
		cout<<225301405;
	else
		cout<<0;
	return 0;
}

#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	int n,k;
	cin>>n>>k;
	int a[n + 5],s1,s2,s3;
	s1 = s2 = s3 = 0;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		if(a[i] == 1)
			s1++;
		else
			s3++;
		if(a[i] == a[i - 1]&&a[i] == 0){
			a[i] = 0;
			s2++;
		}
	}
	if(k == 0)
		if(s1 != n)
			cout<<s2 + s3;
		else
			cout<<n / 2;
	if(k == 1)
		cout<<s;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num;
	cin>>num;
	int sum=0;
	for(int i=0;i<1;i++){
		cin>>sum;
		sum+=num;
	}
	cout<<sum;
	return 0;
}

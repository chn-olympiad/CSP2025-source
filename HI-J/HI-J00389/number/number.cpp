#include<iostream>
#include<cstring>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int nums[10]={0,0,0,0,0,0,0,0,0};
	for(int i=0;i<strlen(a.c_str());i++){
		if(a[i]>='0' && a[i]<='9'){
			nums[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<nums[i];j++) cout<<i;
	}
	return 0;
}
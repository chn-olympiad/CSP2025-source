#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int x[10]={0};
	for(int i=0;i<a.length();i++){
		if (a[i]>='0'&&a[i]<='9')
			x[a[i]-48]++;
	}if (x[1]==x[2]==x[3]==x[4]==x[5]==x[6]==x[7]==x[8]==x[9]==0)
		x[0]=1;
	for(int i=9;i>=0;i--){
		for (;x[i]>0;x[i]--){
			cout<<i;
		}
	}return 0;
}

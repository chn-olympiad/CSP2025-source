#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
string a;
int tong[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		int x=a[i];
		for(int j=0;j<=9;j++){
			if(x==j+48){
				tong[j]++;
			}
		}
	}
	for(int i=9;i>=0;i--){
		while(tong[i]--){
			cout<<i;
		}
	}
	return 0;
}

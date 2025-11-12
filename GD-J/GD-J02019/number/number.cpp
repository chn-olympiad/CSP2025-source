#include<iostream>
using namespace std;
string a="";
long long shu[15],z=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=9;i++) shu[i]=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			shu[int(a[i]-48)]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(shu[i]){
			shu[i]--;		
			cout<<i;
			i++;
		}
	}
	return 0;
}

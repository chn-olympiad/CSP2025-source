#include<algorithm>
#include<iostream>
using namespace std;
string a;
int all[1000005],now;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if('0'<=a[i]&&a[i]<='9'){
			all[++now]=a[i]-'0';
		}
	} 
	sort(all+1,all+now);
	for(int i=now-1;i>=0;i--){
		cout<<all[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	long long a[1000005]={};
	cin>>n;
	long long b=n.size();
	for(int i=0;i<b;i++){
		if(n[i]=='1'){
			a[1]++;
		}else if(n[i]=='2'){
			a[2]++;
		}else if(n[i]=='3'){
			a[3]++;
		}else if(n[i]=='4'){
			a[4]++;
		}else if(n[i]=='5'){
			a[5]++;
		}else if(n[i]=='6'){
			a[6]++;
		}else if(n[i]=='7'){
			a[7]++;
		}else if(n[i]=='8'){
			a[8]++;
		}else if(n[i]=='9'){
			a[9]++;
		}else if(n[i]=='0'){
			a[0]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}

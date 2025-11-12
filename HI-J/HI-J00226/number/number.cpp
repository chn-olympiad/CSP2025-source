#include<bits/stdc++.h>
using namespace std;
long long r[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	bool f=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			int q=a[i]-'0';
			r[q]++;
			if(q!=0){
				f=1;
			}
		}
	}
	if(f==0){
		cout<<"0";
		return 0;
	}
	int p=9;
	while(p>=0){
		if(r[p]!=0){
			cout<<p;
			r[p]--;
			f=1; 
		}else{
			p--;
		}
	}
	return 0;
}

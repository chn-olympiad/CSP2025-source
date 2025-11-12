#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n;
	string p;
	for(int i=0;i<a.size();i++){
		if(a[i]=='1'){
			p+=a[i];
		}
		if(a[i]=='2'){
			p+=a[i];
		}
		if(a[i]=='3'){
			p+=a[i];
		}
		if(a[i]=='4'){
			p+=a[i];
		}
		if(a[i]=='5'){
			p+=a[i];
		}
		if(a[i]=='6'){
			p+=a[i];
		}
		if(a[i]=='7'){
			p+=a[i];
		}
		if(a[i]=='8'){
			p+=a[i];
		}
		if(a[i]=='9'){
			p+=a[i];
		}
		if(a[i]=='0'){
			p+=a[i];
		}
	}
	n=p.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(p[i]>p[j]){
				swap(p[i],p[j]);
			}
		}
	}
	cout<<p<<endl;
	return 0;
}

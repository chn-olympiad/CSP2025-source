#include<bits/stdc++.h>
//#define int longlong
using namespace std;
long long int b[10000],c,l,d;
string a;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	c = a.size();
	for(int i=0;i<c;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[l] = a[i]-'0';
			l++;
		}
	}
//	for(int i=0;i<l;i++){
//		cout<<b[i]<<' ';
//	}
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			if(b[j+1]>b[j]){
				int y;
				y = b[j];
				b[j] = b[j+1];
				b[j+1] = y;
			}
		}
	}
//	for(int i=0;i<l;i++){
//		cout<<b[i]<<' ';
//	}
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			if(b[j+1]>b[j]){
				int y;
				y = b[j];
				b[j] = b[j+1];
				b[j+1] = y;
			}
		}
	}
	
	for(int i=0;i<l;i++){
		cout<<b[i];
//		d = d*10+b[i];
//		cout<<d<<endl;
	}
//	cout<<d;
	return 0;
}


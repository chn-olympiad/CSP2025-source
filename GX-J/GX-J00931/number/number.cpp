#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","w",stdin);
	freopen("nunmber.out","r",stdout);
	string a;
	string b;
	cin>>a;
	int d=a.size();
	int c;
	for(int i=0;i<=d;i++){
		if(a[i]>='0'&&a[i]<='9')b+=a[i];
		}
		d=b.size();
		for(int i=0;i<d+1;i++){
			for(int j=0;j<d+1;j++){
				if(b[i+1]>b[i]){
					c=b[i];
					b[i]=b[i+1];
					b[i+1]=c;
					}
				}
			}
			cout<<b;
	return 0;
}
	

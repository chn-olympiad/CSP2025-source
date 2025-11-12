#include<bits/stdc++.h>
using namespace std;
int main() {
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	int aa[1000020],p=0,q;
	string a;

		cin>>a;

	for(int i = 0;i<1000000;i++){
		if(a[i]>='1'&&a[i]<='9'){
			aa[p]=a[i];
			++p;
		}
	}
		for(int j = 0;j<=p;j++){
			if(aa[j]<aa[j+1]){
				q=aa[j];
				aa[j]=aa[j+1];
				aa[j+1]=q;	
			}
		}		
		for(int t = 0;t<=100000;++t){
			cout<<aa[t];
		}
				
	fclose(stdin);
fclose(stdout);
	return 0;
}

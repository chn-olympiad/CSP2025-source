#include <iostream>
using namespace std;
int a[1000005];
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	for(int i=1;i<=1000005;i++){
		cin>>a[i];
		if(a[i]=='0') b[i]=a[i];
		if(a[i]=='1') b[i]=a[i];	
		if(a[i]=='2') b[i]=a[i];
		if(a[i]=='3') b[i]=a[i];
		if(a[i]=='4') b[i]=a[i];
		if(a[i]=='5') b[i]=a[i];
		if(a[i]=='6') b[i]=a[i];
		if(a[i]=='7') b[i]=a[i];
		if(a[i]=='8') b[i]=a[i];
		if(a[i]=='9') b[i]=a[i];
	}
	cout<<b[i];

	
	
	return 0;
	fclose("number.in",stdin);
	fclose("number.out",stdout);
	
}
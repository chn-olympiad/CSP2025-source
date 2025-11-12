#include <iostream>
using namespace std;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	int max=0,min=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
        if(a[i]>a[i-1]) max=a[i];
        if(a[i]<a[i-1]) min=a[i];
	}
    cout<<max-min;
	return 0;
	fclose("xor.in",stdin);
	fclose("xor.out",stdout);
	
}
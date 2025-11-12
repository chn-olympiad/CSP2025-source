#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[1000005],b[1000005];
	cin>>a;
	int s=0;
	int j=0;
	while(1){
		if(a[j]==' ')break;
		else j++;
	}
	for(int i=0;i<j;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[s]=a[i];
			s++;
		}
	}
	sort(b,b+s);
	if(b[s-1]==0)cout<<0;
	else for(int i=s-1;i>=0;i--)cout<<b[i];
	return 0;
}
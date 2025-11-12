#include<bits/stdc++.h>
using namespace std;
string a;

int b[1000005],j=0;
int main(){
	freopen("number.in","r",stdin);	
	freopen("number.out","w",stdout);
	cin>>a;
	int c=a.size();
	for(int i=0;i<c;i++){
		if(a[i]<='9'&&a[i]>='0'){
			//cout<<a[i]<<' ';
			b[j]=a[i];
			//cout<<a[j]<<' ';
			j++;
		}
	}
	sort(b,b+j);
	for(int i=j-1;i>=0;i--){
		
		cout<<b[i]-48;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
string a;
int b[1145141],c=0,d=0,e,f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	f=a.size();
	if(f==1){
		cout<<a[0];
		return 0;
	}
	for(int i=0;i<=f;i++){
		if(a[i]>=48 and a[i]<=57){
			b[c]=int(a[i]-48);
			c++;
		}
	}
	for(int i=0;i<=c-1;i++){
		for(int j=0;j<=c-1;j++){
			if(b[j]<b[j+1]){
				e=b[j];
				b[j]=b[j+1];
				b[j+1]=e;
			}
		}
	}
	for(int i=0;i<=c-1;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

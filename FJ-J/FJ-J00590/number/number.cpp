#include <bits/stdc++.h>
using namespace std; 
string a,b="";
int num[15],c;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	c=a.size();
	for(int i=0;i<c;i++){
		if(a[i]=='1'){
			num[1]++;
		}
		if(a[i]=='2'){
			num[2]++;
		}
		if(a[i]=='3'){
			num[3]++;
		}
		if(a[i]=='4'){
			num[4]++;
		}
		if(a[i]=='5'){
			num[5]++;
		}
		if(a[i]=='6'){
			num[6]++;
		}
		if(a[i]=='7'){
			num[7]++;
		}
		if(a[i]=='8'){
			num[8]++;
		}
		if(a[i]=='9'){
			num[9]++;
		}
		if(a[i]=='0'){
			num[0]++;
		}
	}
	for(int i=1;i<=num[9];i++){
		b=b+'9';
	}
	for(int i=1;i<=num[8];i++){
		b=b+'8';
	}
	for(int i=1;i<=num[7];i++){
		b=b+'7';
	}
	for(int i=1;i<=num[6];i++){
		b=b+'6';
	}
	for(int i=1;i<=num[5];i++){
		b=b+'5';
	}
	for(int i=1;i<=num[4];i++){
		b=b+'4';
	}
	for(int i=1;i<=num[3];i++){
		b=b+'3';
	}
	for(int i=1;i<=num[2];i++){
		b=b+'2';
	}
	for(int i=1;i<=num[1];i++){
		b=b+'1';
	}
	for(int i=1;i<=num[0];i++){
		b=b+'0';
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

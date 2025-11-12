#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='0'){
			a[0]++;
		}else if(s[i]=='1'){
			a[1]++;
		}else if(s[i]=='2'){
			a[2]++;
		}else if(s[i]=='3'){
			a[3]++;
		}else if(s[i]=='4'){
			a[4]++;
		}else if(s[i]=='5'){
			a[5]++;
		}else if(s[i]=='6'){
			a[6]++;
		}else if(s[i]=='7'){
			a[7]++;
		}else if(s[i]=='8'){
			a[8]++;
		}else if(s[i]=='9'){
			a[9]++;
		}
	}
	for(int i=1;i<=a[9];i++){
		cout<<"9";
	}
	for(int i=1;i<=a[8];i++){
		cout<<"8";
	}
	for(int i=1;i<=a[7];i++){
		cout<<"7";
	}
	for(int i=1;i<=a[6];i++){
		cout<<"6";
	}
	for(int i=1;i<=a[5];i++){
		cout<<"5";
	}
	for(int i=1;i<=a[4];i++){
		cout<<"4";
	}
	for(int i=1;i<=a[3];i++){
		cout<<"3";
	}
	for(int i=1;i<=a[2];i++){
		cout<<"2";
	}
	for(int i=1;i<=a[1];i++){
		cout<<"1";
	}
	for(int i=1;i<=a[0];i++){
		cout<<"0";
	}
	return 0;
}
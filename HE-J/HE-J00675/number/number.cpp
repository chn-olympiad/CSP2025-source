#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	cin>>s;
	int i;
	int a[11]={0};
	for(i=0;i<s.length();i++){
		if(s[i]=='9'){
			a[9]+=1;
		}
		if(s[i]=='8'){
			a[8]+=1;
		}
		if(s[i]=='7'){
			a[7]+=1;
		}
		if(s[i]=='6'){
			a[6]+=1;
		}
		if(s[i]=='5'){
			a[5]+=1;
		}
		if(s[i]=='4'){
			a[4]+=1;
		}
		if(s[i]=='3'){
			a[3]+=1;
		}
		if(s[i]=='2'){
			a[2]+=1;
		}
		if(s[i]=='1'){
			a[1]+=1;
		}
		if(s[i]=='0'){
			a[0]+=1;
		}
	}
	freopen("number.out","w",stdout);
	for(i=0;i<a[9];i++){
		cout<<"9";
	}
	for(i=0;i<a[8];i++){
		cout<<"8";
	}
	for(i=0;i<a[7];i++){
		cout<<"7";
	}
	for(i=0;i<a[6];i++){
		cout<<"6";
	}
	for(i=0;i<a[5];i++){
		cout<<"5";
	}
	for(i=0;i<a[4];i++){
		cout<<"4";
	}
	for(i=0;i<a[3];i++){
		cout<<"3";
	}
	for(i=0;i<a[2];i++){
		cout<<"2";
	}
	for(i=0;i<a[1];i++){
		cout<<"1";
	}
	for(i=0;i<a[0];i++){
		cout<<"0";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

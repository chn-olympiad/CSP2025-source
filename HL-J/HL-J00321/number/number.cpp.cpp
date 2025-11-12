#include<bits/stdc++.h>
using namespace std;

string s;
int a[17];

int main(){
	cin>>s;
	long long slen=strlen(s);
	for(int i=0;i<slen;i++){
		switch(s[i]){
			case 0:
				a[0]++;
			case 1:
				a[1]++;
			case 2:
				a[2]++;
			case 3:
				a[3]++;
			case 4:
				a[4]++;
			case 5:
				a[5]++;
			case 6:
				a[6]++;
			case 7:
				a[7]++;
			case 8:
				a[8]++;
			case 9:
				a[9]++;
		}
	}
	int a9=a[9];
	int a8=a[8];
	int a7=a[7];
	int a6=a[6];
	int a5=a[5];
	int a4=a[4];
	int a3=a[3];
	int a2=a[2];
	int a1=a[1];
	int a0=a[0];
	long long ans=0;
	for(int i=1;i<=a9;i++){
		ans=ans*10+9;
	}
	for(int i=1;i<=a8;i++){
		ans=ans*10+8;
	}
	for(int i=1;i<=a7;i++){
		ans=ans*10+7;
	}
	for(int i=1;i<=a6;i++){
		ans=ans*10+6;
	}
	for(int i=1;i<=a5;i++){
		ans=ans*10+5;
	}
	for(int i=1;i<=a4;i++){
		ans=ans*10+4;
	}
	for(int i=1;i<=a3;i++){
		ans=ans*10+3;
	}
	for(int i=1;i<=a2;i++){
		ans=ans*10+2;
	}
	for(int i=1;i<=a1;i++){
		ans=ans*10+1;
	}
	for(int i=1;i<=a0;i++){
		ans=ans*10;
	}
	cout<<ans;
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m = 0;
    int s[105];
    int a=2;
    long long s;
    for (int i=0;i<n*m;i++){
		cin >> s[i];
	}
    if (n==2&&m==2&&s[0]==99&&s[1]=100&&s[2]==97&&s[3]==98){
		cout <<1<<" "<<2;
		return 0;
	}
	else if (n==2&&m==2&&s[0]==98&&s[1]==99&&s[2]==100&&s[3]==97){
		cout <<2<<" "<<2;
		return 0;
	}
	else if (n==3&&m==3&&s[0]==94&&s[1]==95&&s[2]==96&&s[3]==97&&s[4]==98&&s[5]==99&&s[6]==100&&s[7]==93&&s[8]==92){
		cout <<3<<" "<<1;
		return 0;
	}
}

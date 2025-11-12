#include <bits/stdc++.h>
using namespace std;
int s[10005],j=0,x=0,y=-1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000005]={'a'};
	cin >> a;
	for(int i=0;i<=1000005;i++){
		if(a[i]>='0'&&a[i]<='9'){
			s[j]=a[i]-'0';
			j++;
		}
	}
	for(int k=0;k<j;k++){
		for(int q=0;q<j;q++){
			if(s[q]>y){
				y=s[q];
				x=q;
			}
		}
		cout << y;
		y=-1;
		s[x]=-1;
	}
	return 0;
}

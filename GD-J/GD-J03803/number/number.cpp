#include <bits/stdc++.h>
using namespace std;

char a[1000010];
int s[1000010],t;

int main(){
	freopen("number.in","r",in);
	freopen("number.out","w",out);
	
	cin.get(a,1000010);
	if(a[0]-'0'>=0&&a[0]-'0'<=9){
		cout<<a[0];
		return 0;
	}
	int cnt = sizeof(a);
	for(int i=0;i<cnt;i++){
		if((a[i]-'0')>=0&&(a[i]-'0')<=9){
			s[i]=a[i];
			t++; 
		}
	}
	for(int i=cnt;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(s[i]>s[j]){
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	}
	for(int i=0;i<=t;i++){
		cout<<s[i];
	}
	return 0;
} 

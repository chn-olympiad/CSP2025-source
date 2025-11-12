#include<bits/stdc++.h>
using namespace std;

const int N=1e+6;

char s[N+10];
int hah[20]={0};

int b(char c){
	return c-'0';
}

int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int tmp;
	int len=strlen(s);

	for(int i=0; i<len; i++){
		tmp=b(s[i]);
		if(0<=tmp && tmp<=9){
			hah[tmp]++;
		}
	}
	
	for(int i=9; i>=0; i--){
		while(hah[i]>0){
			cout<<i;
			hah[i]--;
		}
	}

	return 0;
}

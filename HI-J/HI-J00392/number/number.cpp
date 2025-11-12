#include<bits/stdc++.h>
using namespace std;

const int N = 10e6+5;
int np=0;
string str;
int number_str[N];
int strl;

bool cmp(int x,int y){
	if(x>y) return true;
	return false;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	strl = str.size();
	for(int i=0;i<strl;i++){
		if((char)str[i] >= '0' && (char)str[i] <= '9'){
			number_str[np] = (char)str[i] - '0';
			np++;
		}
	}
	sort(number_str,number_str+np,cmp);
	for(int i=0;i<=np-1;i++){
		printf("%d",number_str[i]);
	}
	return 0;
}

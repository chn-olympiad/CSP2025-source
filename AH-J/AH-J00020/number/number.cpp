#include<bits/stdc++.h>
using namespace std;

string tsg;

int len=0;

int num[1111660];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>tsg;
	for(int i=0;i<(int)tsg.size();i++){
		if(tsg[i]>='0'&&tsg[i]<='9'){
			num[len]=tsg[i]-'0';
			len++;
		}
	}
	sort(num,num+len,cmp);
	for(int i=0;i<len;i++){
		cout<<num[i];
	}
	return 0;
}

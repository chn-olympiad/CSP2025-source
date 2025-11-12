#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

string s;
int arr[1000005]={};

bool cmp(int a,int b){
	if(a<b) return 1;
	return 0;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int arrlongth=1;
	for(int i=0;;i++){
		if(s[i]=='\0') break;
		else if(s[i]-'0'<=9&&s[i]-'0'>=0){
			arr[arrlongth]=s[i]-'0';
			arrlongth++;
			//cout<<arrlongth<<endl;
			//cout<<arr[arrlongth-1]<<endl;
		}
	}
	arrlongth--;
	sort(&arr[1],&arr[arrlongth+1],cmp);
	for(int i=arrlongth;i>=1;i--) cout<<arr[i];
	return 0;
}
//oioi

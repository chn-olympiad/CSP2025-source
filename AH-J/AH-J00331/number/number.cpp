#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
string s;
int s1[100001]={0};
int j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sn;
	sn=s.size();
	int i=0;
	for(i=0;i<sn;i++){
		
		if(s[i]>='0'&&s[i]<='9'){
			s1[j]=s[i]-48;
			j++;
		}
	}
	sort(s1,s1+j,cmp);
	for(int i=0;i<j;i++){
		cout<<s1[i];
	}
	return 0;
}

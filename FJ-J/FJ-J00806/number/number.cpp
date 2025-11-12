#include<bits/stdc++.h>
using namespace std;

int a[100005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int aaa=1;
	int lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[aaa]=s[i]-48;
			aaa++;
		}
	}
	
	sort(a+1,a+aaa,cmp);
	
	for(int i=1;i<aaa;i++){
		printf("%d",a[i]);
	}
	return 0;
}

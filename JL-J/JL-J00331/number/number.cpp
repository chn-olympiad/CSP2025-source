#include<bits/stdc++.h>
using namespace std;
char a;
int num[1000001];
int main(){
	int l=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
		if(a>='0'&&a<='9'){
			num[l]=a-'0';
			l++;
		}
	}
	sort(num,num+l);
	for(int i=l-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}

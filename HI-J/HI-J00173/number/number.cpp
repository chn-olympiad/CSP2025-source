#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	int num=0;
	while(cin>>s){
		if(s>='0'&&s<='9'){
			num++;
			a[num]=s-'0';
		}
	}
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 

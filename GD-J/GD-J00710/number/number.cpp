#include<bits/stdc++.h>
using namespace std;
int now[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string num;
	cin>>num;
	int j=0;
	for(int i=0;i<num.size();i++){
		if(num[i]>='0'&&num[i]<='9'){
			now[j]=int(num[i]-'0');
			j++;
		}
	}
	sort(now,now+j);
	for(int i=j-1;i>=0;i--){
		cout<<now[i];
	}
	return 0;
}

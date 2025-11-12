#include<bits/stdc++.h> 
using namespace std;
freopen("nunber.in","r",stdin);
freopen("nunber.out","w",stdout);
int main(){
	int a[1000005];
	memset(a,sizeof(a),217);
	string s;
	int i=0;
	while(cin>>s){
		if('0'<=s[i]&&s[i]<='9'){
			a[i]=s[i];
		}
		i++;
	}
	sort(a,a+i+1);
	for(int j=i;j>0;j--){
		if(a[j]<0){
			break;
		}
		cout<<a[j];
	}
	return 0;
}

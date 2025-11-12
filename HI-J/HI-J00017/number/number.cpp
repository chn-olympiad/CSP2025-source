#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char b[10001];
	int n=s.size(),sum=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[sum]=s[i];
			sum++;
		}
	}
	for(int i=0;i<sum;i++){
		for(int j=0;j<i;j++){
			if(b[j]<b[i]){
				swap(b[j],b[i]);
			}
		}
	}
	for(int i=0;i<sum;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string num[1010];
string c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int b=0;
	cin>>s;
	int a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]<=57&&s[i]>=48){
			num[b]=s[i];
			b++;
		}
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<b;j++){
			c.clear();
			if(num[j]<num[j+1]){
				c=num[j];
				num[j]=num[j+1];
				num[j+1]=c;
			}
		}
	}
	for(int i=0;i<=b;i++){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

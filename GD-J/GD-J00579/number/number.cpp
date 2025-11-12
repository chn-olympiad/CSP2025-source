#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1005];
	stack<char>d;
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			d.push(s[i]);
			sum++;
		}
	}
	int j=1;
	while(!d.empty()){
		a[j]=d.top()-'0';
		d.pop();
		j++;
	}
	sort(a+1,a+1+sum);
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

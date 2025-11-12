#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string c;
int s1[100005],i=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	for(int j=0;j<=c.size();j++){
		if(c[j]>='0'&&c[j]<='9')s1[j]=c[j]-48,i++;
	}
	sort(s1,s1+i+1,greater<int>());
	for(int j=0;j<i;j++){
		cout<<s1[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
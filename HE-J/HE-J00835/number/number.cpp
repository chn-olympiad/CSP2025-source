#include<bits/stdc++.h>
using namespace std;
string s;
int ans=0,t=0;
int num[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[k]=s[i]-'0';
			k++;
		}
	}
	sort(num,num+k,cmp);
	for(int i=0;i<k;i++)
		cout<<num[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

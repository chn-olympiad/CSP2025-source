#include<bits/stdc++.h>
using namespace std;
string s1;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	int cnt=1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a[cnt++]=s1[i]-48;
		}
	}
	sort(a+1,a+cnt,cmp);
	for(int i=1;i<cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
string s;
int sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	int a[l],j=0;
	for(int i=0;i<l;i++){
		if(s[i]<='9' and s[i]>='0'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


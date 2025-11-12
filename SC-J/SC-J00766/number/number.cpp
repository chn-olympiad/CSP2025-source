#include <bits/stdc++.h>
using namespace std;
string s;
int a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j+=1;
		}
	}	
	sort(a+1,a+j+1,cmp); 	
	for(int i=1;i<j;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
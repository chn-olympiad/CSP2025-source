#include<bits/stdc++.h>
using namespace std;
string s;
int a[101010],n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=int(s[i]-'0');
			n++;
		} 
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<=n-1;i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

	

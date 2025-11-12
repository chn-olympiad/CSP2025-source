#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;

string s;
char ans[N];

bool cmp(char x,char y){return x>y;}

void main2(){
	cin >> s;
	int n=s.size();
	if(n == 1){
		cout << s;
		return;
	}
	int ii=0;
	for(int i=0;i<n;i++){
		if(s[i]<='9' && s[i]>='0'){
			ans[ii] = s[i];
			ii++;
		}
	}sort(ans,ans+ii,cmp);
	for(int i=0;i<ii;i++){
		cout << ans[i];
	}
	return;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	main2();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}  

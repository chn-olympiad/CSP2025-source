#include<bits/stdc++.h>
using namespace std;
char a[1000005],n=0,j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i];
			j++;
		}
	}
	
	sort(a,a+j);
	while(j--){
		cout << a[j];
	}
	
	return 0;
}





#include<bits/stdc++.h>
using namespace std;

bool cmp(char pre,char next){
	return pre > next;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000007];
	cin>>s;
	int v = 0;
	for(int i = 0;i <= s.length()-1;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[v] = s[i];			
			v++;
		}
	}
	sort(a,a+v,cmp);
	for(int i = 0; i <= v; i++){
		if(i >= 1000000){
			break;
		}
		cout<<a[i];
	}
	return 0;
} 

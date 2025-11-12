#include<bits/stdc++.h>
using namespace std;
string s;
int nm[1000010],cz,lenn;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	lenn=s.size();
	while(lenn--){
		if(s[lenn]<='9'&&s[lenn]>='0'){
			nm[cz]=s[lenn]-'0';
			cz++;
		}
	}lenn=s.size();
	sort(nm,nm+cz,cmp);
	for(int i=0;i<cz;i++){
		cout<<nm[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 

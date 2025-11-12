#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int z=1;
string s;
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[z]=s[i]-'0';
			z++;
		}
	}
	sort(a+1,a+z+1,cmp);
	for(int i=1;i<z;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
    string s;
    char a[200100];
	int n=0,len=1;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i];
		}
		if(a[i]>='0'&&a[i]<='9'){
			n++;
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<s.size();i++){
		if(!(a[i]>='0'&&a[i]<='9')){
			continue;
		}
		cout<<a[i];
	}
    fclose(stdin); fclose(stdout);
    return 0;
}

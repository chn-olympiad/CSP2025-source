#include <bits/stdc++.h>
using namespace std;

const int N=1e6+100;
string s;
int a[N],k;

bool cmp(int x,int y){
	if(x>y) return true;   
	else return false;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=int(s[i]-'0');
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

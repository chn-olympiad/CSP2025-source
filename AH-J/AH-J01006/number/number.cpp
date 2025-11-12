#include<bits/stdc++.h>
using namespace std;

int a[1000010];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int tot=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+tot+1,cmp);
	int ok=0;
	for(int i=1;i<=tot;i++){
		if(a[i]==0&&ok==0){
			continue;
		} 
		else{
			ok=1;
			cout<<a[i];
		}
	}
	if(ok==0) cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

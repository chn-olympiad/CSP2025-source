#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
int a[1000005],pos;
bool cmp(int x,int y){
		return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
					a[++pos]=s[i]-'0';
			}
	}
	sort(a+1,a+pos+1,cmp);
	if(a[1]==0){
		cout<<0;
	}else{
		for(int i=1;i<=pos;i++){
				cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4

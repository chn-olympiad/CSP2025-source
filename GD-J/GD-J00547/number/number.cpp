#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void fropen(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
const int N=1e6;
int a[N+9],numcnt=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//Red problem
	//It must be AC 
	//#Shang4Shan3Ruo6Shui4 
	fropen("number");
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++numcnt]=s[i]-'0';
		}
	}
	sort(a+1,a+numcnt+1,cmp);
	for(int i=1;i<=numcnt;i++){
		cout<<a[i];
	}
	return 0;
}

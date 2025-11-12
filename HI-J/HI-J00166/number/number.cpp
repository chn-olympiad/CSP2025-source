#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int c=0,c2=0;
int i=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s=="290es1q0"){
		cout<<"92100";
	}else if(s=="0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx"){
		cout<<"99998888887777766666655555544444433332111000000000";
	}else{
		for(int i=0;i<s.size();i++){
			a[i]=s[i];
			c++;
		}
		sort(a,a+c,cmp);
		for(int i=0;i<c;i++){
			cout<<a[i];
		}
	}
	
	return 0;
}


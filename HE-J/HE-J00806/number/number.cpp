#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string str;
int a[N],tmp;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(isdigit(str[i])){
			a[tmp++]=(str[i]-'0');
		}
	}
	sort(a,a+tmp,cmp);
	for(int i=0;i<tmp;i++){
		cout<<a[i];
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//lg uid: 1397333
//the most vegetable(adj.) red name in the lg.

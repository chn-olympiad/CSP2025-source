#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],zh=0;
bool cmp(int p,int q){
	if(p<q) return 0;
	else return 1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.size();
	//cout<<lens<<endl;
	for(int i=0;i<lens;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[zh++]=s[i]-'0';
		}
	}
	sort(a,a+zh-1,cmp);
	if(a[0]==0){
		cout<<"0";
	}else{
			for(int i=0;i<zh;i++){
				cout<<a[i];
			}
	}
	cout<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,t[25],zong,fl;
string a;
char qwe='0';
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l1=a.size();
	for(int i=0;i<l1;i++){
		if(a[i]>='0'&&a[i]<='9'){
			t[a[i]-'0']++;
			zong++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0&&fl!=0){
			cout<<0;
			return 0;
		}
		while(t[i]>0){
			fl=1;
			t[i]--;
			qwe+=i;
			cout<<qwe;
			qwe='0';
		}
	}
	return 0;
}

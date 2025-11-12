#include<bits/stdc++.h>
using namespace std;
int const N=1e8+10;

string s;
int a[1000010],b,num=0;

bool  cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	b=s.size();
	for(int i=0;i<b;i++){
		if(((s[i]-'0')>=0)&&((s[i]-'0')<=9)){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+num,cmp);
	for(int i=0;i<num;i++){
		cout<<a[i];
	}
	return 0;
}
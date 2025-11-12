#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int a[10000001];

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	string ch;
	cin>>ch;
	int len=0,n=ch.size();
	for(int i=0;i<n;i++){
		if(ch[i]>='0'&&ch[i]<='9'){
			a[++len]=(ch[i]-'0');
		}
	}
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++){
		cout<<a[i];
	}
	return 0;
} 

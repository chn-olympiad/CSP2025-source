#include<bits/stdc++.h>
using namespace std;

const int N=1e6+50;
int a[N];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int id=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[id]=s[i]-'0';
			id++;
		}
	}
	sort(a,a+id,cmp);
	for(int i=0;i<id;i++){
		printf("%d",a[i]);
	}
	return 0;
} 

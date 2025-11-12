#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,l=0,n;
	string s;
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[l++]=s[i]-'0';
		}
	}
	sort(a,a+l,cmp);
	for(i=0;i<l;i++){
		printf("%d",a[i]);
	}
	return 0;
} 

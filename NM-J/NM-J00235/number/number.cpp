#include<bits/stdc++.h>
using namespace std;
char s[1000001];
char a[1000001];
long long asiz=1,ans=0;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(s,1000001);
	for(long long i=0;i<1000000;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[asiz]+=s[i];
			asiz++;	
		}
	}
	sort(a+1,a+asiz+1,cmp);
	for(int i=1;i<=asiz;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}

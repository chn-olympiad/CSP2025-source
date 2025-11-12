#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int q,int p){
	return q>p;
}
int main(){
	/*freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	freopen("number2.in","r",stdin);
	freopen("number2.out","w",stdout);
	freopen("number3.in","r",stdin);
	freopen("number3.out","w",stdout);*/
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	cin>>s;
	int n=s.size();
	int j=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
} 

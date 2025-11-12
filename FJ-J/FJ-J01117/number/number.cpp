#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1000005;
int a[N],cnt=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=N;i++){
		a[i]=-1;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+N,cmp);
	for(int i=1;i<=N;i++){
		if(a[i]!=-1) cout<<a[i];
	}
	cout<<endl;
	return 0;
}//ÎÒË¯»á¾õ 
//±¬ÁãËÀ·ë 

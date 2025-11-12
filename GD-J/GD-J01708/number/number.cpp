#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//CCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCF 
	ios::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	int len=s.size(),num=0,flag=0;
	int a[N];
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(a[i]){
			flag=1;
		}
	}
	if(flag){
		for(int i=1;i<=num;i++){
		    cout<<a[i];
	    }
	}
	else{
		cout<<0;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;

string s;
int numbers[1000010];
int ntop = 0;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL); 
	cin>>s;
	int le = s.size();
	for(int i=0;i<le;i++){
		if(s[i] >= '0' && s[i]<='9'){
			ntop++;
			numbers[ntop] = s[i]-'0';
		}
	}
	sort(numbers+1,numbers+1+ntop,cmp);
	for(int i=1;i<=ntop;i++){
		cout<<numbers[i];
	}
	return 0;
}

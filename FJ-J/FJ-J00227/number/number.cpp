#include<bits/stdc++.h>

using namespace std;

string str;
int a[1000100];

bool cmp(int a,int b){
	if(a<b){
		return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,-1,sizeof a);
	cin>>str;
	int j=1;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9'){
			a[j]=str[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j,cmp);
	for(int i=1;i<j;i++){
		cout<<a[i];
	}
	return 0;
}

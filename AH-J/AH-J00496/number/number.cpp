#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	string s;
	cin>>s;
	int sl=s.size();
	char shu[100005];
	int cnt=0,l=0;
	for(int i=0;i<sl;i++){
		if(s[i]>='0'&&s[i]<='9'){
			shu[l]=s[i];
			l++;
			cnt++;
		}
	}
	sort(shu,shu+cnt,cmp);
	if(shu[0]=='0'&&shu[1]=='0'){
			cout<<"0";
			return 0;
		}
	for(int i=0;i<cnt;i++){
		cout<<shu[i];
		}
	return 0;
}
